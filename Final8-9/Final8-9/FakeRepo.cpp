#include "FakeRepo.h"
#include "Controller.hpp"

void FakeRepo::add(const Evidence& evidence)
{
	cout << "Evidence added!" << endl;
}

int FakeRepo::remove(const std::string& id)
{
	cout << "Evidence removed!" << endl;
	return 1;
}

int FakeRepo::update(const Evidence& evidence)
{
	cout << "Evidence updated!" << endl;
	return 1;
}

void FakeRepo::test()
{
	FakeRepo* fake_repo = new FakeRepo();
	Controller* ctrl = new Controller{ fake_repo };
	ctrl->add("valid_id", "valid_measurement", 100, 200, "valid_photo");
	ctrl->remove("valid_id");
	ctrl->update("valid_id", "valid_measurement", 100, 200, "valid_photo");
}