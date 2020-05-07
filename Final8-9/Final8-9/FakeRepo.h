#pragma once
#include "Domain.hpp"
#include "Repository.hpp"

class FakeRepo:public Repository
{
public:
	FakeRepo() {};
	~FakeRepo() {};
	void add(const Evidence& evidence);
	int remove(const std::string& id);
	int update(const Evidence& evidence);
	void test();


	std::vector<Evidence> getEvidences() { std::vector<Evidence> e; return e; }
	int getPosition(const std::string& id) { return 0; }
	int getSize() { return 0; }
	void saveToFile() {};
};

