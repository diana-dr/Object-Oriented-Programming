#include "Repository.h"
#include <string>

using namespace std;

int Repository::addEvidence(const Evidence &evidence)
{
    this->evidences.add(evidence);
    return 1;
}

int Repository::removeEvidence(const Evidence& evidence)
{
    int position = findPosition(evidence);
    this->evidences.remove(evidence, position);
    return 1;
}

int Repository::updateEvidence(Evidence old_evidence, Evidence new_evidence)
{
    old_evidence.setImageClarity(new_evidence.getImageClarity());
    old_evidence.setMeasurement(new_evidence.getMeasurement());
    old_evidence.setPhotograph(new_evidence.getPhotograph());
    old_evidence.setQuantity(new_evidence.getQuantity());
    this->evidences.update(new_evidence, findPosition(old_evidence));
    return 1;
}

int Repository::findPosition(const Evidence& evidence)
{
    for (int i = 0; i < this->evidences.getSize(); i++)
    {
        Evidence e = this->evidences[i];
        if (evidence.getId() == e.getId())
            return i;
    }
}

Evidence Repository::findByID(const std::string &id)
{
    Evidence* evidenceInDynamicVector = this->evidences.getAllElements();
    if (evidenceInDynamicVector == nullptr)
        return Evidence{};

    for (int i = 0; i < this->evidences.getSize(); i++)
    {
        Evidence evidence = this->evidences[i];
        if (evidence.getId() == id)
            return evidence;
    }
}