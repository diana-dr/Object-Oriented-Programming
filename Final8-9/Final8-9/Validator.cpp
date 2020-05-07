#include "Validator.hpp"

using namespace std;

EvidenceException::EvidenceException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> EvidenceException::getErrors() const
{
	return this->errors;
}

void EvidenceValidator::validate(const Evidence& evidence)
{
	vector<string> errors;
	if (evidence.getId().size() < 1)
		errors.push_back("The id cannot be less than 1 character!\n");
	if (evidence.getMeasurement().size() < 1)
		errors.push_back("The measurement type cannot be less than 1 character!\n");
	if (evidence.getQuantity() < 0)
		errors.push_back("The quantity can not be negative!\n");
	if (evidence.getImageClarity() < 0)
		errors.push_back("The image clarity level can not be negative!\n");
	if (evidence.getPhotograph().size() < 1)
		errors.push_back("The measurement type cannot be less than 1 character!\n");

	if (errors.size() > 0)
		throw EvidenceException(errors);
}
