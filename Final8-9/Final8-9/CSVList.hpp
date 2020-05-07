#pragma once
#ifndef CSVList_hpp
#define CSVList_hpp

#include <stdio.h>

#pragma once
#include "EvidenceList.hpp"
class CSVList :public EvidenceList
{
private:
	std::string fileName;
public:
	CSVList(std::string fileName);
	~CSVList();

	void saveToFile();
	void openInApp();
};

#endif /* CSVList_hpp */


