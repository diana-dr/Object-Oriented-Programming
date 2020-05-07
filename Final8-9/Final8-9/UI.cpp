#include "UI.hpp"
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include "Utils.hpp"
#include "RepositoryExceptions.hpp"

UI::~UI()
{
}

UI::UI(Controller ctrl, EvidenceList* myList)
{
	this->ctrl = ctrl;
	this->myList = myList;
}

void UI::run()
{

	this->ctrl.saveToFile();
	this->myList->saveToFile();
	while (true)
	{
		printMenu();
		std::string command;
		std::getline(std::cin, command);
		if (command == "exit")
			break;

		if (command == "mode A")
		{
			runAdmin();
			this->myList->saveToFile();
			break;
		}
		if (command == "mode B")
		{
			{
				runUser();
				this->myList->saveToFile();
				break;
			}
		}
		std::cout << "Invalid command!\n";
	}
	this->ctrl.saveToFile();
	this->myList->saveToFile();
}

void UI::runAdmin()
{
	while (true)
	{
		printMenuAdmin();
		std::string command, input;
		std::getline(std::cin, input);
		command = input.substr(0, input.find(" "));
		if (command == "exit")
			break;
		if (command == "add")
		{
			add_ui(input);
			continue;
		}
		if (command == "delete")
		{
			remove_ui(input);
			continue;
		}
		if (command == "update")
		{
			update_ui(input);
			continue;
		}
		if (command == "list")
		{
			list_ui();
			continue;
		}
		if (input == "mode B")
		{
			runUser();
			break;
		}
		std::cout << "Invalid command!\n";
	}
}

void UI::runUser()
{
	while (true)
	{
		printMenuUser();
		std::string command, input;
		std::getline(std::cin, input);
		command = input.substr(0, input.find(" "));
		if (command == "exit")
			break;
		if (command == "next")
		{
			nextEvidence(input);
			continue;
		}
		if (command == "list")
		{
			filter(input);
			continue;
		}
		if (command == "mylist")
		{
			this->myList->saveToFile();
			openInApp();
			continue;
		}

		if (command == "save")
		{
			addToMyList(input);
			continue;
		}

		/*if (command == "open")
		{
			this->myList->saveToFile();
			openInApp();
			continue;
		}*/
		if (input == "mode A")
		{
			runAdmin();
			break;
		}
		std::cout << "Invalid command!\n";
	}
}

void UI::printMenu()
{
	cout << "Available modes:" << endl;
	cout << "mode A: senior clearance level" << endl;
	cout << "mode B: standard clearance level" << endl;
	cout << "Choose a mode: ";
}

void UI::printMenuAdmin()
{
	cout << endl;
	cout << "Senior clearance level" << endl;
	cout << "add evidence." << endl;
	cout << "update evidence." << endl;
	cout << "delete evidence." << endl;
	cout << "list." << endl;
	cout << "exit." << endl;
	cout << "Choose: ";
}

void UI::printMenuUser()
{
	cout << endl;
	cout << "Standard clearance level" << endl;
	cout << "see evidence one by one" << endl;
	cout << "download evidence" << endl;
	cout << "go to net evidence" << endl;
	cout << "list by measurement and quantity" << endl;
	cout << "show my list" << endl;
	cout << "open my list in app" << endl;
	cout << "Choose: ";
}

void UI::add_ui(std::string command)
{
	command.erase(0, command.find(" ") + 1);
	std::string id, measurement, photo;
	int image_clarity, quantity;

	id = command.substr(0, command.find(", "));
	command.erase(0, command.find(", ") + 1);
	measurement = command.substr(0, command.find(", "));
	command.erase(0, command.find(", ") + 1);
	image_clarity = stoi(command.substr(0, command.find(", ")));
	command.erase(0, command.find(", ") + 1);
	quantity = stoi(command.substr(0, command.find(", ")));
	command.erase(0, command.find(", ") + 1);
	photo = command.substr(0, command.find(", "));

	try
	{
		this->ctrl.add(id, measurement, (image_clarity), (quantity), photo);
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}
}

void UI::filter(string command)
{
	std::string measurement;
	int quantity;

	command.erase(0, command.find(" ") + 1);
	measurement = command.substr(0, command.find_first_of(" ,"));
	command.erase(0, command.find_first_of(" ,") + 1);
	quantity = stoi(command.substr(0, command.find_first_of(" ,")));

	for (auto evidence: this->ctrl.getEvidences())
		if (evidence.getMeasurement() == measurement && quantity <= evidence.getQuantity())
			printEvidence(evidence);
}

void UI::remove_ui(std::string command)
{
	std::string id;
	id = command.erase(0, command.find(" ") + 1);

	try
	{
		this->ctrl.remove(id);
	}
	catch (EvidenceException& e)
	{
		for (auto s : e.getErrors())
			std::cout << s;
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}
	catch (DuplicateEvidenceException& e)
	{
		std::cout << e.what() << '\n';
	}
	catch (FileException& e)
	{
		std::cout << e.what() << '\n';
	}
}

void UI::update_ui(std::string command)
{
	std::string id, measurement, photo;
	int  image_clarity, quantity;
	command.erase(0, command.find(" ") + 1);
	id = command.substr(0, command.find(" "));
	command.erase(0, command.find(" ") + 1);
	measurement = command.substr(0, command.find(" "));
	command.erase(0, command.find(" ") + 1);
	image_clarity = stoi(command.substr(0, command.find(" ")));
	command.erase(0, command.find(" ") + 1);
	quantity = stoi(command.substr(0, command.find(" ")));
	command.erase(0, command.find(" ") + 1);
	photo = command.substr(0, command.find(" "));

	try
	{
		this->ctrl.update(id, measurement, (image_clarity), (quantity), photo);
	}
	catch (EvidenceException& e)
	{
		for (auto s : e.getErrors())
			std::cout << s;
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}
	catch (FileException& e)
	{
		std::cout << e.what() << '\n';
	}
}

void UI::list_ui()
{
	for (auto e : this->ctrl.getEvidences())
		printEvidence(e);
}

void UI::addToMyList(std::string command)
{
	std::string id = command.erase(0, command.find(" ") + 1);
	Evidence evidence = this->ctrl.findEvidence(id);

	this->myList->addById(evidence);

}

void UI::nextEvidence(std::string command)
{
	std::string measurement = command.erase(0, 5);

	this->myList->getActiveList(this->ctrl.getEvidences(), measurement);

	if (this->myList->getActive().size() == 0)
		std::cout << "No evidences with this measurement\n";
	else
	{
		this->myList->nextActive();
		Evidence evidence = this->myList->getCurrentEvidence();
		printEvidence(evidence);
	}
}

void UI::list_mylist()
{
	if (this->myList->getMyList().size() == 0)
		std::cout << "No evidence in your list!\n";
	else
		for (auto e : this->myList->getMyList())
			printEvidence(e);
}

void UI::printEvidence(Evidence evidence)
{
	cout << "ID: " << evidence.getId() << setw(6);
	cout << " Measurement: " << evidence.getMeasurement() << setw(10);
	cout << " Image clarity level: " << evidence.getImageClarity() << setw(10);
	cout << " Quantity: " << evidence.getQuantity() << setw(10);
	cout << " Photograph: " << evidence.getPhotograph();
	cout << endl;
}

void UI::saveToFile()
{
	this->myList->saveToFile();
}

void UI::openInApp()
{
	this->myList->openInApp();
}

