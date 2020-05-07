#define _CRT_SECURE_NO_WARNINGS
#include "CSVList.hpp"
#include <Windows.h>
#include <shellapi.h>

CSVList::CSVList(std::string fileName)
{
	this->fileName = fileName;
}


CSVList::~CSVList()
{
}

void CSVList::saveToFile()
{
	std::ofstream f(this->fileName);
	for (auto evidence : this->myList)
		f << evidence << "\n";
	f.close();
}

void CSVList::openInApp()
{
	/*std::string cmd = "open " + this->fileName;
	system(cmd.c_str());*/

	char file[sizeof(this->fileName) + 4];
	const char * fileName = this->fileName.c_str();
	strcpy(file, fileName);
	char exe[sizeof(this->fileName) + 13];
	/*strcpy(exe, "notepad.exe ");

	strcat(exe, file);
	system(exe);*/

	// ShellExecute(NULL, "open", this->fileName.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
