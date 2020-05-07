#define _CRT_SECURE_NO_WARNINGS
#include "UI.hpp"
#include "FakeRepo.h"
#include "CSVList.hpp"
#include "HTMLlist.hpp"
#include "FileRepository.hpp"
#include <Windows.h>
#include <conio.h>

int main()
{
	//FakeRepo* fr = new FakeRepo();
	//fr->test();
	
	/*Tests t;
	t.TestAll();*/

	std::string path_txt;
	//path_txt = "C:\\Users\\Diana\\source\\repos\\Final8-9\\file.txt";
	cout << "Choose file location: ";
	std::getline(std::cin, path_txt);
	path_txt.erase(0, path_txt.find(" ") + 1);
	
	std::string type, path;
	type = "html";
	////path = "C:\\Users\\Diana\\source\\repos\\Final8-9\\list.html";
	cout << "Location for mylist: ";
	std::getline(std::cin, path);
	path.erase(0, path.find(" ") + 1);
	type = path.substr(path.find(".") + 1, path.length() + 1);
	
	if (type == "csv" || type == "html")
	{
	    MemoryRepo* admin_repo = new FileRepository{ path_txt };
	
	    EvidenceList* user_repo;
	    if (type == "csv")
	        user_repo = new CSVList(path);
	    else
	        user_repo = new HTMLlist(path);
	
	    Controller* admin_ctrl = new Controller{ admin_repo };
	    UI* ui = new UI(*admin_ctrl, user_repo);
	
	    ui->run();
	}
}
