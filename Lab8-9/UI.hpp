#pragma once
#include "Controller.hpp"
#include "Exception.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UI
{
private:
    Controller controller;
    
public:
    UI(const Controller& ctrl) : controller(ctrl) {}
    std::vector<Evidence> getAllEvidences() const { return this->controller.getEvidences_ctrl(); }
    Evidence findByGivenID(const std::string &id) { return this->controller.findBiGivenID_ctrl(id); }
    void run();
    
private:
    void splitCommand(char command[], char *input_command[40]);
    int searchById(char* id);
    void printEvidence(Evidence evidence);
    // void showEvidence(char *input);
    void nextEvidence(char*input);
    void saveID(char* input);
    void list_by_measurement(char *input);
    void my_list();
    static void printMenu_for_senior();
    static void printMenu_for_standard();
    void run_senior(string file, string myList);
    void run_standard(string file, string myList);
    void addEvidence_ui(char* input);
    void deleteEvidence_ui(char* input);
    void updateEvidence_ui(char* input);
    void list();
    void readEvidences(string fileLocation);
    void writeEvidences(string fileLocation);
    void readMyList(string myList);
    void writeToMyList(string myList);
};
