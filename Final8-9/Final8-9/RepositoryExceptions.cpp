#include "RepositoryExceptions.hpp"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateEvidenceException::what()
{
	return "There is another evidence with the same id!";
}

const char * InexistingEvidenceException::what()
{
	return "There are no evidence with the given id!";
}
