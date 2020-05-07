#pragma once
#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "Controller.hpp"

class UI
{
private:
	Controller ctrl;
	EvidenceList* myList;
public:
	// UI();
	UI(Controller ctrl, EvidenceList* myList);
	~UI();

	void run();

private:
	void runAdmin();
	void runUser();

	static void printMenu();
	static void printMenuAdmin();
	static void printMenuUser();

	void add_ui(std::string command);
	void remove_ui(std::string command);
	void update_ui(std::string command);
	void list_ui();

	void addToMyList(std::string command);
	void nextEvidence(std::string command);
	void list_mylist();
	void saveToFile();
	void openInApp();

	void printEvidence(Evidence evidence);
	void filter(string command);

};


#endif /* UI_hpp */
