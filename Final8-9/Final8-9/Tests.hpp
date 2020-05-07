#pragma once
#ifndef Tests_hpp
#define Tests_hpp

#include <stdio.h>

class Tests
{
public:
	Tests();
	~Tests();

	void TestAll();

	void testController();
	void testHTML();
	void testEvidence();
	void testRepository();
	void testFileRepository();
	void testMemoryRepo();
	void testRepositoryException();
	void testUtil();
	void testValidator();
	void testEvidenceList();
};


#endif /* Tests_hpp */


