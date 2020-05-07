#pragma once
#ifndef MemoryRepo_hpp
#define MemoryRepo_hpp

#include <stdio.h>
#include "Repository.hpp"

class MemoryRepo : public Repository
{
protected:
	std::vector<Evidence> evidences;
	EvidenceValidator validator;

public:
	MemoryRepo();
	~MemoryRepo();

	MemoryRepo(const MemoryRepo& other) { this->evidences = other.evidences; }
	MemoryRepo& operator=(const MemoryRepo& other);

	std::vector<Evidence> getEvidences() { return this->evidences; }
	int getSize() { return this->evidences.size(); }

	void add(const Evidence& evidence);
	int remove(const std::string& id);
	int update(const Evidence& evidence);
	int getPosition(const std::string& id);
	void saveToFile();
};


#endif /* MemoryRepo_hpp */


