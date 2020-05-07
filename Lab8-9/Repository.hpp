#pragma once
#include "Domain.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Repository
{
private:
    std::vector<Evidence> evidences;
    
public:
    
    // Default constructor
    // Initializes an object of type repository
    
    Repository() {};
    
    int addEvidence(const Evidence& evidence);
    int removeEvidence(const Evidence& evidence);
    int updateEvidence(Evidence old_evidence, Evidence new_evidence);
    int findPosition(const Evidence& evidence);
    
    Evidence findByID(const std::string& id);
    std::vector<Evidence> getEvidences() const { return evidences; }
    
};
