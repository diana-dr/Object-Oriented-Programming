#pragma once
#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Repository.hpp"
#include "EvidenceList.hpp"

class Controller
{
private:
	Repository *repository;
public:
	Controller();
	Controller(Repository* repo) { this->repository = repo; }
	~Controller();

	void add(const std::string& id, const std::string measurement, const int& image_clarity, const int& quantity, std::string photo);
	int remove(const std::string& id) { return this->repository->remove(id); }
	int update(const std::string& id, const std::string measurement, const int& image_clarity, const int& quantity, std::string photo);
	void saveToFile() { this->repository->saveToFile(); }
	Evidence findEvidence(std::string id);

	int getSize() { return this->repository->getSize(); }
	int getPosition(const std::string& id) { return this->repository->getPosition(id); }
	std::vector<Evidence> getEvidences() { return this->repository->getEvidences(); }

};

#endif /* Controller_hpp */


