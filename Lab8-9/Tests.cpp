#include "Tests.hpp"

using namespace std;

void TestRepository()
{
    Repository repository;
    const string& a = "abc";
    const string& b = "bcd";
    
    Evidence evidence{ a, a, 5, 6, a };
    Evidence evidence2{ b, b, 3, 4, b };
    Evidence evidence3{ a, b, 6, 7, b };
    
    assert(repository.addEvidence(evidence) == 1);
    assert(repository.addEvidence(evidence2) == 1);
    
    assert(repository.getEvidences().size() == 2);
    
    assert(repository.addEvidence(evidence3) == -1);
    
    assert(repository.removeEvidence(evidence) == 1);
    
    assert(repository.updateEvidence(evidence, evidence3) == -1);
    assert(repository.updateEvidence(evidence2, evidence3) == 1);
    
    repository.findByID(a) = evidence2;
    assert(true);
}

void TestController()
{
    Repository repository;
    Controller controller{ repository };
    
    const string& a = "abc";
    const string& b = "bcd";
    const string& c = "ccd";
    
    Evidence evidence{ a, a, 5, 6, a };
    Evidence evidence2{ b, b, 3, 4, b };
    Evidence evidence3{ c, c, 6, 7, b };
    
    assert(controller.addEvidence_ctrl(evidence) == 1);
    assert(controller.addEvidence_ctrl(evidence) == -1);
    
    controller.findBiGivenID_ctrl(a) = evidence;
    assert(true);
    
    assert(controller.addEvidence_ctrl(evidence3) == 1);
    
    assert(controller.deleteEvidence_ctrl(evidence2) == -1);
    
    assert(controller.addEvidence_ctrl(evidence2) == 1);
    assert(controller.deleteEvidence_ctrl(evidence2) == 1);
    
    assert(controller.updateEvidence_ctrl(evidence, evidence2) == 1);
    
    controller.download_to_evidenceList_ctrl(evidence);
    assert(true);
    controller.download_to_evidenceList_ctrl(evidence3);
    assert(true);
    
    assert(controller.getEvidenceList().size() == 2);
    assert(controller.getEvidences_ctrl().size() == 2);
    
    assert(controller.currentPosition(evidence) == 0);
    
    controller.getCurrentEvidence() = evidence;
    assert(true);
}

void TestAll()
{
    TestRepository();
    TestController();
}
