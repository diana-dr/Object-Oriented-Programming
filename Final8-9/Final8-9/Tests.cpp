#include "Tests.hpp"
#include "UI.hpp"
#include "FileRepository.hpp"
#include "CSVList.hpp"
#include "HTMLlist.hpp"
#include <assert.h>
#include "RepositoryExceptions.hpp"

Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::TestAll()
{
	try
	{

		testFileRepository();
	}
	catch (FileException& e)
	{
		std::cout << e.what() << '\n';
	}

	testHTML();

	try
	{
		testController();
	}
	catch (RepositoryException e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		testMemoryRepo();
	}
	catch (RepositoryException e)
	{
		std::cout << e.what() << "\n";
	}
	testEvidence();
	testRepository();
	testRepositoryException();
	testUtil();
	testValidator();
	testEvidenceList();

}


void Tests::testController()
{
	Controller c = Controller();
	MemoryRepo* admin_repo = new FileRepository("evidences.txt");
	MemoryRepo a;
	MemoryRepo b;
	b = a;
	a.saveToFile();

	FileRepository admin_repo1 = FileRepository("evidences.txt");
	FileRepository admin_repo2;
	admin_repo2 = admin_repo1;
	admin_repo1 = admin_repo1;

	admin_repo->saveToFile();


	Controller admin_ctrl = Controller(admin_repo);

	admin_ctrl.add("valid_id", "valid_measurement", 100, 2020, "valid_photo");
	Evidence e = admin_ctrl.findEvidence("valid_id");
	int res = admin_ctrl.update("valid_id", "valid_measurement2", 2008, 87, "valid_photo2");
	res = admin_ctrl.getSize();
	res = admin_ctrl.getPosition("valid_id");
	admin_ctrl.saveToFile();
	std::vector<Evidence> it = admin_ctrl.getEvidences();
	res = admin_ctrl.remove("valid_id");
	admin_ctrl.saveToFile();
	throw RepositoryException();
}

void Tests::testFileRepository()
{
	FileRepository r;
	FileRepository r2 = r;
}

void Tests::testHTML()
{
	EvidenceList* newList = new HTMLlist("Resources\mylist.html");
	std::vector<Evidence> a = newList->getActive();
	newList->nextActive();
	Evidence e = Evidence( "valid_id", "valid_measurement", 100, 2020, "valid_photo" );
	int pos = newList->getPosition(e);
	Repository* repo = new FileRepository();

	Evidence e1 = Evidence("valid_id1", "valid_measurement1", 110, 11110, "valid_photo1");
	repo->add(e1);
	Evidence e2 = Evidence("valid_id2", "valid_measurement2", 110, 2110, "valid_photo2");
	repo->add(e2);
	newList->getActiveList(repo->getEvidences(), "");
	newList->getActiveList(repo->getEvidences(), "valid_measurement");
	Evidence e3 = newList->getCurrentEvidence();
	newList->nextActive();
	e3 = newList->getCurrentEvidence();

	newList->getActiveList(repo->getEvidences(), "valid_measurement1");
	newList->add();
	newList->add();
	newList->getPosition(e);
}

void Tests::testMemoryRepo()
{
	Repository* repo = new FileRepository();

	Evidence e1 = Evidence("valid_id1", "valid_measurement1", 110, 11110, "valid_photo1");
	repo->add(e1);
	int res = repo->getPosition("valid_id1");
	assert(res != -1);
	res = repo->getPosition("valid_id1");
	Evidence e2 = Evidence("valid_id2", "valid_measurement2", 110, 2110, "valid_photo2");

	repo->update(e1);

	try
	{
		Evidence e1 = Evidence("valid_id1", "valid_measurement1", 110, 11110, "valid_photo1");
		repo->add(e1);
	}
	catch (DuplicateEvidenceException e)
	{
		std::cout << e.what() << '\n';
	}


	Evidence e3 = Evidence("valid_id1", "valid_measurement3", 200, 2020, "valid_photo3");
	repo->update(e3);

	std::vector<Evidence> evidences = repo->getEvidences();
	assert(evidences.size() == 1);

	assert(evidences[0].getId() == "valid_id1");

	repo->remove("valid_id1");

	std::vector<Evidence> new_evidences = repo->getEvidences();
	assert(new_evidences.size() == 0);

	try
	{
		Evidence e01 = Evidence("", "valid_measurement3", 200, 2020, "valid_photo3");
		repo->add(e01);
	}
	catch (EvidenceException& e)
	{
		for (auto s : e.getErrors())
			std::cout << s;
	}

	try
	{
		Evidence e02 = Evidence("valid_id", "valid_measurement3", -1, 2020, "valid_photo3");
		repo->add(e02);
	}
	catch (EvidenceException& e)
	{
		for (auto s : e.getErrors())
			std::cout << s;
	}

	try
	{
		Evidence e03 = Evidence("valid_id", "", -1, 2020, "valid_photo3");
		repo->add(e03);
	}
	catch (EvidenceException& e)
	{
		for (auto s : e.getErrors())
			std::cout << s;
	}
}

void Tests::testEvidence()
{
	Evidence e1 = Evidence();
	Evidence e{ "valid_id", "valid_measurement", 200, 2020, "valid_photo" };
	assert(e.getId() == "valid_id");
	assert(e.getMeasurement() == "valid_measurement");
	assert(e.getImageClarity() == 200);
	assert(e.getQuantity() == 2020);
	assert(e.getPhotograph() == "valid_photo");
	Evidence e2 = Evidence(e);
}

void Tests::testRepository()
{}

void Tests::testRepositoryException()
{}

void Tests::testUtil()
{}

void Tests::testValidator()
{}

void Tests::testEvidenceList()
{}