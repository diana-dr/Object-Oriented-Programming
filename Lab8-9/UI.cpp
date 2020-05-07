#define _CRT_SECURE_NO_WARNINGS
#include "UI.hpp"
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

void UI::run()
{
    char input[100];
    char copy_input[100];
    string filename;
    string myList;
    
    cout << "Choose file: ";
    
    cin.getline(input, sizeof(input));
    strcpy(copy_input, input);
    
    char *option = std::strtok(input, " ,=/");
    
    if (strcmp(input, "fileLocation") == 0)
    {
        filename = copy_input;
        filename.replace(0, 13, "");
    }
    
    readEvidences(filename);
    
    cout << "Location for mylist: ";
    
    cin.getline(input, sizeof(input));
    strcpy(copy_input, input);
    
    option = std::strtok(input, " ,=/");
    
    if (strcmp(input, "myListLocation") == 0)
    {
        myList = copy_input;
        myList.replace(0, 15, "");
    }
    
    readMyList(myList);
    
    cout << "Available modes:" << endl;
    cout << "mode A: senior clearance level" << endl;
    cout << "mode B: standard clearance level" << endl;
    cout << "Choose a mode: ";
    
    cin.getline(input, sizeof(input));
    strcpy(copy_input, input);
    
    option = std::strtok(input, ",=/");
    
    if (strcmp(input, "mode A") == 0)
        run_senior(filename, myList);
    else if (strcmp(input, "mode B") == 0)
        run_standard(filename, myList);
    else if (strcmp(option, "exit") == 0) {
        writeEvidences(filename);
        writeToMyList(myList);
        return;
    }
    else {
        try
        {
            throw Exception("Invalid command!\n");
        }
        catch (const Exception& exception)
        {
            std::cout << exception.what() << std::endl;
        }
        run();
    }
}

void UI::run_standard(string filename, string myList)
{
    while (true)
    {
        printMenu_for_standard();
        char input[100];
        char copy_input[100];
        // char *string;
        
        cout << "Choose an option: ";
        
        cin.getline(input, sizeof(input));
        strcpy(copy_input, input);
        
        char *option = std::strtok(copy_input, " ,=/");
        
        //         std::strtol(option, &string, 10);
        //         if (strcmp(option, nullptr) == 0 || std::strcmp(string, "XX") == 0)
        //             showEvidence(input);
        if (strcmp(option, "next") == 0)
            nextEvidence(input);
        
        else if (strcmp(input, "mode A") == 0)
        {
            run_senior(filename, myList);
            break;
        }
        else if (strcmp(input, "mode B") == 0)
        {
            run_standard(filename, myList);
            break;
        }
        else if (strcmp(option, "save") == 0)
            saveID(input);
        else if (strcmp(option, "list") == 0)
            list_by_measurement(input);
        else if (strcmp(option, "mylist") == 0)
            my_list();
        else if (strcmp(option, "exit") == 0) {
            writeToMyList(myList);
            writeEvidences(filename);
            break;
        }
        else
        {
            try
            {
                throw Exception("Invalid command!\n");
            }
            catch (const Exception& exception)
            {
                std::cout << exception.what() << std::endl;
            }
        }
    }
}

void UI::run_senior(string filename, string myList)
{
    while (true) {
        printMenu_for_senior();
        char input[100];
        char copy_input[100];
        
        cout << "Choose an option: ";
        
        cin.getline(input, sizeof(input));
        strcpy(copy_input, input);
        
        char *option = std::strtok(copy_input, " ,=/");
        
        if (strcmp(option, "exit") == 0) {
            writeToMyList(myList);
            writeEvidences(filename);
            break;
        }
        else if (strcmp(input, "mode B") == 0)
        {
            run_standard(filename, myList);
            break;
        }
        else if (strcmp(input, "mode A") == 0)
            run_senior(filename, myList);
        else if (strcmp(option, "add") == 0)
            addEvidence_ui(input);
        else if (strcmp(option, "delete") == 0)
            deleteEvidence_ui(input);
        else if (strcmp(option, "update") == 0)
            updateEvidence_ui(input);
        else if (strcmp(option, "list") == 0)
            list();
        else {
            try
            {
                throw Exception("Invalid command!\n");
            }
            catch (const Exception& exception)
            {
                std::cout << exception.what() << std::endl;
            }
        }
    }
}

void UI::printMenu_for_standard()
{
    cout << endl;
    cout << "Standard clearance level" << endl;
    cout << "see evidence one by one" << endl;
    cout << "download evidence" << endl;
    cout << "go to net evidence" << endl;
    cout << "list by measurement and quantity" << endl;
    cout << "show my list" << endl;
}

void UI::printMenu_for_senior()
{
    cout << endl;
    cout << "Senior clearance level" << endl;
    cout << "add evidence." << endl;
    cout << "update evidence." << endl;
    cout << "delete evidence." << endl;
    cout << "list." << endl;
    cout << "exit." << endl;
}

void UI::splitCommand(char command[], char *splitedCommand[7])
{
    int parameterNumber = 0;
    char *stringsOfCommand;
    stringsOfCommand = strtok(command, " ,?!=/");
    
    while (stringsOfCommand != NULL)
    {
        strcpy(splitedCommand[parameterNumber], stringsOfCommand);
        stringsOfCommand = strtok(NULL, " ,?!=/");
        parameterNumber++;
    }
}

//void UI::showEvidence(char *input)
//{
//    char *command[10];
//    const int parameters = 7;
//
//    for (int i = 0; i < parameters; i++)
//    {
//        command[i] = new char[100];
//    }
//
//    splitCommand(input, command);
//    this->controller.filter_by_measurement(command[1]);
//    Evidence evidence = this->controller.getCurrentEvidence();
//    printEvidence(evidence);
//}

void UI::printEvidence(Evidence evidence)
{
    cout << "ID: " << evidence.getId() << setw(6);
    cout << " Measurement: " << evidence.getMeasurement() << setw(10);
    cout << " Image clarity level: " << evidence.getImageClarity() << setw(10);
    cout << " Quantity: " << evidence.getQuantity() << setw(10);
    cout << " Photograph: " << evidence.getPhotograph();
    cout << endl;
}

void UI::nextEvidence(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    
    splitCommand(input, command);
    this->controller.filter_by_measurement(command[1]);
    Evidence evidence = this->controller.nextActive();
    printEvidence(evidence);
}

void UI::saveID(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    splitCommand(input, command);
    if (searchById(command[1]) == 0)
        cout << "No evidence with given id" << endl;
    else
        this->controller.download_to_evidenceList_ctrl(findByGivenID(command[1]));
}

int UI::searchById(char* id)
{
    int found = 0;
    for (int i = 0; i < this->getAllEvidences().size(); i++)
        if (this->getAllEvidences()[i].getId() == id)
            found = 1;
    return found;
}

void UI::my_list()
{
    if (this->controller.getEvidenceList().size() == 0)
        cout << "Nothing to show!" << endl;
    else
        for (int i = 0; i < this->controller.getEvidenceList().size(); i++)
            printEvidence(this->controller.getEvidenceList()[i]);
}

void UI::list_by_measurement(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    splitCommand(input, command);
    for (int i = 0; i < this->controller.getEvidences_ctrl().size(); i++)
        if (this->controller.getEvidences_ctrl()[i].getMeasurement() == command[1] && std::atoi(command[2]) <= this->controller.getEvidences_ctrl()[i].getQuantity())
            printEvidence(this->controller.getEvidences_ctrl()[i]);
}

void UI::addEvidence_ui(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    
    splitCommand(input, command);
    
    try
    {
        for (int i = 0; i < strlen(command[3]); i++)
            if (!isdigit(command[3][i]))
                throw Exception("The third argument needs to be an integer!\n");
        for (int i = 0; i < strlen(command[4]); i++)
            if (!isdigit(command[4][i]))
                throw Exception("The fourth argument needs to be an integer!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
        return;
    }
    
    Evidence evidence(command[1], command[2], std::atoi(command[3]),
                      std::atoi(command[4]), command[5]);
    int result = this->controller.addEvidence_ctrl(evidence);
    
    try
    {
        if (result != 1)
            throw Exception("Could not add evidence!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
}

void UI::deleteEvidence_ui(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    
    splitCommand(input, command);
    
    Evidence evidence = this->findByGivenID(command[1]);
    int result = this->controller.deleteEvidence_ctrl(evidence);
    
    try
    {
        if (result != 1)
            throw Exception("Could not delete evidence!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
}

void UI::updateEvidence_ui(char* input)
{
    char *command[10];
    const int parameters = 7;
    
    for (int i = 0; i < parameters; i++)
    {
        command[i] = new char[100];
    }
    
    splitCommand(input, command);
    Evidence old_evidence = this->findByGivenID(command[1]);
    
    try
    {
        if (old_evidence.getId() == "")
            throw Exception("Could not find evidence with given id!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
    Evidence new_evidence(command[1], command[2], std::atoi(command[3]),
                          std::atoi(command[4]), command[5]);
    
    int result = this->controller.updateEvidence_ctrl(old_evidence, new_evidence);
    
    /*try
     {
     if (result != 1)
     throw Exception("Could not update evidence!\n");
     }
     catch (Exception& exception)
     {
     std::cout << exception.what() << std::endl;
     }*/
    
}

void UI::list()
{
    vector<Evidence> evidences = this->getAllEvidences();
    if (evidences.size() == 0)
    {
        cout << endl;
        cout << "No evidence available!" << endl;
        return;
    }
    for (auto evidence : this->getAllEvidences())
    {
        cout << "ID: " << evidence.getId() << setw(6);
        cout << " Measurement: " << evidence.getMeasurement() << setw(10);
        cout << " Image clarity level: " << evidence.getImageClarity() << setw(10);
        cout << " Quantity: " << evidence.getQuantity() << setw(10);
        cout << " Photograph: " << evidence.getPhotograph();
        cout << endl;
    }
}

void UI::readEvidences(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
        return;
    
    Evidence evidence{};
    while (file >> evidence)
    {
        this->controller.addEvidence_ctrl(evidence);
    }
    
    file.close();
}

void UI::writeEvidences(string filename)
{
    ofstream file;
    file.open(filename);
    
    try
    {
        if (!file.is_open())
            throw Exception("Could not open given file!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
    vector<Evidence> evidences = this->getAllEvidences();
    
    for (auto evidence : evidences)
    {
        file << evidence;
    }
    
    file.close();
}

void UI::readMyList(string myList)
{
    ifstream file(myList);
    if (!file.is_open())
        return;
    
    Evidence evidence{};
    while (file >> evidence)
    {
        this->controller.download_to_evidenceList_ctrl(evidence);
    }
    
    file.close();
}

void UI::writeToMyList(string myList)
{
    ofstream file(myList);
    int position = myList.find_last_of(".");
    
    string path = myList;
    
    try
    {
        if (!file.is_open())
            throw Exception("Could not open given file!\n");
    }
    catch (Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
    vector<Evidence> evidences = this->controller.getActiveList();
    
    if (path.replace(0, position + 1, "") == "html")
    {
        char quotes = '"';
        
        file << "<!DOCTYPE html>\n";
        file << "<html>\n";
        file << "<head>\n";
        file << "<title>Evidences</title>\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "<table border=" << "1" << ">\n";
        file << "<tr>\n";
        file << "<td>" << "Id" <<"</td>\n";
        file << "<td>" << "Measurement" <<"</td>\n";
        file << "<td>" << "Image clarity level" <<"</td>\n";
        file << "<td>" << "Quantity" <<"</td>\n";
        file << "<td>" << "Photograph" <<"</td>\n";
        file << "</tr>\n";
        for (auto evidence : evidences)
        {
            file << "<tr>\n";
            file << "<td>" << evidence.getId() <<"</td>\n";
            file << "<td>" << evidence.getMeasurement() <<"</td>\n";
            file << "<td>" << evidence.getImageClarity() <<"</td>\n";
            file << "<td>" << evidence.getQuantity() <<"</td>\n";
            file << "<td><a href=" << quotes << evidence.getPhotograph() << quotes <<">Link</a></td>\n";
            file << "</tr>\n";
        }
        
        file << "</table>\n";
        file << "</body>\n";
        file << "</html>\n";
    }
    else if (path.replace(0, position + 1, "") == "csv")
    {
        for (auto evidence : evidences)
        {
            file << evidence;
        }
    }
    file.close();
}
