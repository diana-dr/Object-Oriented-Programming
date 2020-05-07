#define _CRT_SECURE_NO_WARNINGS
#include "Controller.hpp"

int Controller::addEvidence_ctrl(Evidence evidence)
{
    return this->repository.addEvidence(evidence);
    
}

int Controller::deleteEvidence_ctrl(Evidence evidence)
{
    return this->repository.removeEvidence(evidence);
}

int Controller::updateEvidence_ctrl(Evidence oldEvidence, Evidence newEvidence)
{
    return this->repository.updateEvidence(oldEvidence, newEvidence);
}

void Controller::download_to_evidenceList_ctrl(Evidence evidence)
{
    this->evidenceList.push_back(evidence);
}

void Controller::filter_by_measurement(const char* measurement)
{
    this->activeList.clear();
    for (int i = 0; i < this->getEvidences_ctrl().size(); i++)
    {
        if (strcmp(measurement, "") == 0)
            this->activeList.push_back(getEvidences_ctrl()[i]);
        else {
            if (this->getEvidences_ctrl()[i].getMeasurement() == measurement)
                this->activeList.push_back(getEvidences_ctrl()[i]);
        }
    }
}

Evidence Controller::getCurrentEvidence()
{
    return activeList[this->current];
}

int Controller::currentPosition(Evidence evidence)
{
    int position = 0;
    for (int i = 0; i < this->activeList.size(); i++)
        if (this->activeList[i].getId() == evidence.getId())
            position = i;
    return position;
}

Evidence Controller::nextActive() {
    this->current = this->currentPosition(this->getCurrentEvidence());
    if (this->activeList.size() == current)
        current = 0;
    Evidence evidence = this->getCurrentEvidence();
    this->current++;
    return evidence;
}

void Controller::writeToCSV(ofstream file)
{
    
    for (auto s : this->activeList)
        file << s << "\n";
    
    file.close();
}
