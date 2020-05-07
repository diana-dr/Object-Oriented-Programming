#include "Repository.h"

class Controller
{
private:
    Repository& repository;
    DynamicVector<Evidence> evidenceList;
    DynamicVector<Evidence> activeList;
    int current = -1;

public:
    Controller(Repository& repo) : repository{ repo } {}

    Repository& getRepo() const { return repository; }
    DynamicVector<Evidence> getEvidenceList() const { return evidenceList; }
    DynamicVector<Evidence> getEvidences_ctrl() const { return this->getRepo().getEvidences(); }
    Evidence findBiGivenID_ctrl(const std::string &id) { return this->getRepo().findByID(id); }
    int currentPosition(Evidence evidence);
    // DynamicVector<Evidence> & getMyList() const { return this->evidenceList.getAll(); }


    // Adds evidence with the given data to the repository
    int addEvidence_ctrl(Evidence evidence);
    int deleteEvidence_ctrl(Evidence evidence);
    int updateEvidence_ctrl(Evidence oldEvidence, Evidence newEvidence);
    void filter_by_measurement(char* measurement);

    // Adds given data to evidence list
    void download_to_evidenceList_ctrl(Evidence evidence);

    // returns the current evidence
    Evidence getCurrentEvidence();

    // gets to the next evidence
    Evidence nextActive();

};