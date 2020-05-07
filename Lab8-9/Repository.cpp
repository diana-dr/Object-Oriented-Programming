#define _CRT_SECURE_NO_WARNINGS
#include "Repository.hpp"
#include "Exception.hpp"
#include <string>
#include <algorithm>
#include <exception>

int Repository::addEvidence(const Evidence &evidence)
{
    for (auto evidence1 : evidences)
    {
        try
        {
            if (evidence.getId() == evidence1.getId())
            {
                throw Exception("Evidence already in!\n");
            }
        }
        catch (Exception& exception)
        {
            std::cout << exception.what() << endl;
            return -1;
        }
        
    }
    evidences.push_back(evidence);
    return 1;
}

int Repository::removeEvidence(const Evidence& evidence)
{
    vector<Evidence>::iterator it;
    it = evidences.begin();
    int pos = findPosition(evidence);
    int i = 0;
    
    if (pos == -1)
        return -1;
    
    while (i != pos)
    {
        it++;
        i++;
    }
    
    evidences.erase(it);
    return 1;
}

int Repository::updateEvidence(Evidence old_evidence, Evidence new_evidence)
{
    vector<Evidence>::iterator it;
    it = evidences.begin();
    int pos = findPosition(old_evidence);
    int i = 0;
    
    try
    {
        if (pos == -1)
        {
            throw Exception("Could not update evidence!\n");
        }
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << endl;
        return -1;
    }
    
    while (i != pos)
    {
        it++;
        i++;
    }
    
    it->setImageClarity(new_evidence.getImageClarity());
    it->setMeasurement(new_evidence.getMeasurement());
    it->setPhotograph(new_evidence.getPhotograph());
    it->setQuantity(new_evidence.getQuantity());
    
    old_evidence.setImageClarity(new_evidence.getImageClarity());
    old_evidence.setMeasurement(new_evidence.getMeasurement());
    old_evidence.setPhotograph(new_evidence.getPhotograph());
    old_evidence.setQuantity(new_evidence.getQuantity());
    
    return 1;
}

int Repository::findPosition(const Evidence& evidence)
{
    for (int i = 0; i < this->evidences.size(); i++)
    {
        Evidence e = this->evidences[i];
        if (evidence.getId() == e.getId())
            return i;
    }
    return -1;
}

Evidence Repository::findByID(const std::string &id)
{
    for (auto evidence : evidences)
    {
        if (evidence.getId() == id)
            return evidence;
    }
    return Evidence{};
}
