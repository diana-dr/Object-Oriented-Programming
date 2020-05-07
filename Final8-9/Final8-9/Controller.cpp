#include "Controller.hpp"
#include "Controller.hpp"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::add(const std::string& id, const std::string measurement, const int& image_clarity, const int& quantity, std::string photo)
{
	this->repository->add(Evidence{ id, measurement, image_clarity, quantity, photo });
}

int Controller::update(const std::string& id, const std::string measurement, const int& image_clarity, const int& quantity, std::string photo)
{
	return this->repository->update(Evidence{ id, measurement, image_clarity, quantity, photo });
}

Evidence Controller::findEvidence(std::string id)
{
	for (auto evidence : this->getEvidences())
	{
		if (evidence.getId() == id)
			return evidence;
	}
	return Evidence{};
}

