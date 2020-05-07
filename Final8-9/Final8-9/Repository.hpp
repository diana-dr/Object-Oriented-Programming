#pragma once
#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include "Domain.hpp"
#include "Validator.hpp"

class Repository
{
public:
	//Repository();
	// ~Repository();

	virtual std::vector<Evidence> getEvidences() = 0;
	virtual int getPosition(const std::string& id) = 0;
	virtual int getSize() = 0;

	virtual void add(const Evidence& evidence) = 0;
	virtual int remove(const std::string& id) = 0;
	virtual int update(const Evidence& evidence) = 0;
	virtual void saveToFile() = 0;
};
#endif /* Repository_hpp */
