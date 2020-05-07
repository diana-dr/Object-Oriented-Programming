#pragma once
#ifndef HTMLlist_hpp
#define HTMLlist_hpp

#include <stdio.h>
#include "EvidenceList.hpp"
class HTMLlist : public EvidenceList
{
private:
	std::string fileName;
public:
	HTMLlist(std::string fileName);
	~HTMLlist();

	void saveToFile();
	void openInApp();
};

#endif /* HTMLlist_hpp */


