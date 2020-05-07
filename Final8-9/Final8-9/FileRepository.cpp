#include "FileRepository.hpp"
#include "Utils.hpp"
#include "RepositoryExceptions.hpp"

FileRepository::FileRepository()
{
}

FileRepository::FileRepository(const FileRepository &other) : MemoryRepo(other)
{
	this->filename = other.filename;
	loadFromFile();
}

FileRepository::~FileRepository()
{
}


void FileRepository::loadFromFile()
{
	std::ifstream file(this->filename);

	try {
		if (!file.is_open())
			throw FileException("File could not be opened\n");
	}
	catch (FileException& exception)
	{
		file.close();
		std::cout << "File was created! " << std::endl;
		std::cout << exception.what() << std::endl;
		return;
	}

	Evidence evidence{};
	while (file >> evidence)
	{
		this->add(evidence);
	}

	file.close();

}

void FileRepository::saveToFile()
{
	ofstream file(this->filename);
	try {
		if (!file.is_open())
			throw FileException("File could not be opened\n");
	}
	catch (FileException& exception)
	{
		file.close();
		std::cout << exception.what() << std::endl;
		return;
	}

	vector<Evidence> evidences = this->getEvidences();

	for (auto evidence : evidences)
	{
		file << evidence;
	}

	file.close();
}

FileRepository& FileRepository::operator=(const FileRepository& other)
{
	if (this == &other)
		return *this;
	MemoryRepo::operator=(other);
	this->filename = other.filename;

	return *this;
}
