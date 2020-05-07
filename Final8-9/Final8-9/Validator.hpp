#pragma once
#include <string>
#include "Domain.hpp"
#include <vector>

class EvidenceException
{
private:
	std::vector<std::string> errors;

public:
	EvidenceException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class EvidenceValidator
{
public:
	EvidenceValidator() {}
	static void validate(const Evidence& evidence);
};


