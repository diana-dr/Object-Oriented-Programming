#include "Domain.h"
#include "DynamicVector.h"

class Repository
{
private:
    DynamicVector<Evidence> evidences;

public:

    // Default constructor
    // Initializes an object of type repository

    Repository() {};

    int addEvidence(const Evidence& evidence);
    int removeEvidence(const Evidence& evidence);
    int updateEvidence(Evidence old_evidence, Evidence new_evidence);
    int findPosition(const Evidence& evidence);

    Evidence findByID(const std::string& id);
    DynamicVector<Evidence> getEvidences() const { return evidences; }

};