#include "EvidenceList.hpp"

EvidenceList::EvidenceList()
{
	this->myList = std::vector<Evidence>();
	this->currentPos = -1;
	this->activeList = std::vector<Evidence>();
	this->type = "";
}

EvidenceList::EvidenceList(std::string fileName)
{
	this->myList = std::vector<Evidence>();
	this->currentPos = -1;
	this->activeList = std::vector<Evidence>();
	this->type = type;
}

EvidenceList::~EvidenceList() {}

void EvidenceList::add()
{
	this->myList.push_back(this->activeList[this->currentPos]);
}

void EvidenceList::addById(Evidence evidence)
{
	this->myList.push_back(evidence);
}

void EvidenceList::getActiveList(std::vector<Evidence> repo, std::string measurement)
{
	vector<Evidence> list;
	if (measurement == "")
		list = repo;
	else
	{
		for (auto evidence : repo)
			if (evidence.getMeasurement() == measurement)
				list.push_back(evidence);
	}
	this->activeList = list;
	// this->currentPos = -1;
}

int EvidenceList::getPosition(Evidence evidence)
{
	int index = 0;
	for (auto evidence1 : this->activeList)
	{
		if (evidence1.getId() == evidence.getId())
			return index;
		index++;
	}
	return -1;
}

Evidence EvidenceList::getCurrentEvidence()
{
	if (this->currentPos == this->activeList.size())
		this->currentPos = -1;
	return this->activeList[this->currentPos];
}

void EvidenceList::nextActive()
{
	if (this->currentPos == this->activeList.size() - 1)
		this->currentPos = 0;
	else
		this->currentPos++;
}
