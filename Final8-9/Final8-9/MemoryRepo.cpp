#include "MemoryRepo.hpp"
#include "RepositoryExceptions.hpp"

MemoryRepo::MemoryRepo()
{
	this->evidences = std::vector<Evidence>();
	this->validator = EvidenceValidator();
}

MemoryRepo::~MemoryRepo() {}

MemoryRepo& MemoryRepo::operator=(const MemoryRepo& other)
{
	if (this == &other) return *this;
	this->evidences = other.evidences;
	return *this;
}

void MemoryRepo::add(const Evidence &evidence)
{
	validator.validate(evidence);
	if (getPosition(evidence.getId()) != -1)
		throw DuplicateEvidenceException();
	this->evidences.push_back(evidence);
}

int MemoryRepo::remove(const std::string &id)
{
	int pos = getPosition(id);
	if (pos == -1)
		throw InexistingEvidenceException();

	this->evidences.erase(this->evidences.begin() + pos);
	return 1;
}

int MemoryRepo::update(const Evidence &evidence)
{
	int pos = getPosition(evidence.getId());
	if (pos == -1)
		throw InexistingEvidenceException();

	this->evidences[pos] = evidence;
	return 1;
}

int MemoryRepo::getPosition(const std::string& id)
{
	int i = 0;
	for (auto evidence : this->evidences)
	{
		if (evidence.getId() == id)
			return i;
		i++;
	}
	return -1;
}

void MemoryRepo::saveToFile()
{}
