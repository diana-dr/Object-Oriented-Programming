#pragma once
#ifndef FileRepository_hpp
#define FileRepository_hpp

#include <stdio.h>
#include "MemoryRepo.hpp"

class FileRepository : public MemoryRepo
{
private:
	std::string filename;
	void loadFromFile();

public:
	FileRepository();
	FileRepository(const std::string& filename) : MemoryRepo() { this->filename = filename; loadFromFile(); }
	FileRepository(const FileRepository& other);
	~FileRepository();

	FileRepository& operator=(const FileRepository& other);
	void saveToFile() override;
};


#endif /* FileRepository_hpp */


