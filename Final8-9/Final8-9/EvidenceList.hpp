#pragma once
#ifndef EvidenceList_hpp
#define EvidenceList_hpp

#include <stdio.h>
#include "Domain.hpp"
#include <vector>

class EvidenceList
{
protected:
	std::vector<Evidence> myList;
	std::vector<Evidence> activeList;
	int currentPos;
	std::string type;

public:
	EvidenceList();
	EvidenceList(std::string measurement);
	~EvidenceList();

	void add();
	void addById(Evidence evidence);

	std::vector<Evidence> getActive() { return this->activeList; }
	void getActiveList(std::vector<Evidence> repo, std::string measurement);
	std::vector<Evidence> getMyList() { return this->myList; }
	int getPosition(Evidence evidence);
	int getCurrentPosition() { return this->currentPos; }
	Evidence getCurrentEvidence();
	std::string getType() const { return this->type; }

	void nextActive();

	virtual void saveToFile() = 0;
	virtual void openInApp() = 0;
};

#endif /* EvidenceList_hpp */


