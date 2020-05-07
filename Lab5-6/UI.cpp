#include "UI.h"
#include <iostream>
#include <stdio.h>
#include <string>

void UI::run()
{
    char input[100];
    char copy_input[100];

    cout << "Available modes:" << endl;
    cout << "mode A: senior clearance level" << endl;
    cout << "mode B: standard clearance level" << endl;
    cout << "Choose a mode: ";

    cin.getline(input, sizeof(input));
    strcpy(copy_input, input);

    char *option = std::strtok(input, ",=/");

    if (strcmp(input, "mode A") == 0)
        run_senior();
    else if (strcmp(input, "mode B") == 0)
        run_standard();
    else if (strcmp(option, "exit") == 0)
        return ;
    else {
        cout << "Invalid option!";
        run();
    }

}

void UI::run_standard()
{
     while(true)
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
             run_senior();
             break ;
         }
         else if (strcmp(input, "mode B") == 0)
         {
             run_standard();
             break ;
         }
         else if (strcmp(option, "save") == 0)
             saveID(input);
         else if (strcmp(option, "list") == 0)
             list_by_measurement(input);
         else if (strcmp(option, "mylist") == 0)
             my_list();
         else if (strcmp(option, "exit") == 0)
             break ;
         else
             cout << "Invalid command!" << endl;
     }
}

void UI::run_senior()
{
    while(true) {
        printMenu_for_senior();
        char input[100];
        char copy_input[100];

        cout << "Choose an option: ";

        cin.getline(input, sizeof(input));
        strcpy(copy_input, input);

        char *option = std::strtok(copy_input, " ,=/");

        if (strcmp(option, "exit") == 0)
            break ;
        else if (strcmp(input, "mode B") == 0)
        {
            run_standard();
            break ;
        }
        else if (strcmp(input, "mode A") == 0)
            run_senior();
        else if (strcmp(option, "add") == 0)
            addEvidence_ui(input);
        else if (strcmp(option, "delete") == 0)
            deleteEvidence_ui(input);
        else if (strcmp(option, "update") == 0)
            updateEvidence_ui(input);
        else if (strcmp(option, "list") == 0)
            list();
        else
            cout << "Invalid command!" << endl;
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
    for (int i = 0; i < this->getAllEvidences().getSize(); i++)
        if (this->getAllEvidences()[i].getId() == id)
            found = 1;
    return found;
}

void UI::my_list()
{
    if (this->controller.getEvidenceList().getSize() == 0)
        cout << "Nothing to show" << endl ;
    else
        for (int i = 0; i < this->controller.getEvidenceList().getSize(); i++)
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
    for (int i = 0; i < this->controller.getEvidences_ctrl().getSize(); i++)
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

    Evidence evidence(command[1], command[2], std::atoi(command[3]),
            std::atoi(command[4]), command[5]);
    int result = this->controller.addEvidence_ctrl(evidence);

    if (result == 1)
        cout << "Evidence added successfully!" << endl;
    else
        cout << "Evidence could not be added!" << endl;

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

    if (result == 1)
        cout << "Evidence deleted successfully!" << endl;
    else
        cout << "Could not delete evidence!" << endl;
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
    Evidence new_evidence(command[1], command[2], std::atoi(command[3]),
                          std::atoi(command[4]), command[5]);

    int result = this->controller.updateEvidence_ctrl(old_evidence, new_evidence);

    if (result == 1)
        cout << "Evidence updated successfully!" << endl;
    else
        cout << "Could not update the evidence!" << endl;
}

void UI::list()
{
    DynamicVector<Evidence> evidences = this->getAllEvidences();
    if (evidences.getSize() == 0)
    {
        cout << endl;
        cout << "No evidence available!" << endl;
        return ;
    }
    for (int i = 0; i < evidences.getSize(); i++)
    {
        Evidence evidence = evidences[i];
        cout << "ID: " << evidence.getId() << setw(6);
        cout << " Measurement: " << evidence.getMeasurement() << setw(10);
        cout << " Image clarity level: " << evidence.getImageClarity() << setw(10);
        cout << " Quantity: " << evidence.getQuantity() << setw(10);
        cout << " Photograph: " << evidence.getPhotograph();
        cout << endl;
    }
}

