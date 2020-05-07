#include "Controller.h"

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
    this->evidenceList.add(evidence);
}

void Controller::filter_by_measurement(char* measurement)
{
    this->activeList.clear();
    // this->current = -1;
    for (int i = 0; i < this->getEvidences_ctrl().getSize(); i++)
    {
        if (strcmp(measurement, "") == 0)
            this->activeList.add(getEvidences_ctrl()[i]);
        else {
            if (this->getEvidences_ctrl()[i].getMeasurement() == measurement)
                this->activeList.add(getEvidences_ctrl()[i]);
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
    for (int i = 0; i < this->activeList.getSize(); i++)
    {
        if (this->activeList[i].getId() == evidence.getId())
            position = i;
    }
    return position;
}

Evidence Controller::nextActive() {
    this->current = this->currentPosition(this->getCurrentEvidence());

    if (this->activeList.getSize() == current)
        current = 0;

    Evidence evidence = this->getCurrentEvidence();

    this->current++;
    return evidence;
}