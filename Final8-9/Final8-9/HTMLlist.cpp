#include "HTMLlist.hpp"
#include <Windows.h>
#include <shellapi.h>

HTMLlist::HTMLlist(std::string fileName)
{
	this->fileName = fileName;
}

HTMLlist::~HTMLlist()
{
}

void HTMLlist::saveToFile()
{

	std::ofstream file(this->fileName);

	file << "<!DOCTYPE html>" << "\n";
	file << "<html>" << "\n";

	file << "<head>" << "\n";
	file << "<title>Evidences</title>" << "\n";
	file << "</head>" << "\n";

	file << "<body>" << "\n";

	file << "<table border=\"1\">" << "\n";

	file << "<tr>" << "\n";
	file << "<td>Id</td>" << "\n";
	file << "<td>Measurement</td>" << "\n";
	file << "<td>Image Clariry Level</td>" << "\n";
	file << "<td>Quantity</td>" << "\n";
	file << "<td>Photograph</td>" << "\n";
	file << "</tr>" << "\n";

	for (auto evidence : this->myList)
	{
		file << "<tr>" << "\n";

		file << "<td>" << evidence.getId() << "</td>" << "\n";
		file << "<td>" << evidence.getMeasurement() << "</td>" << "\n";
		file << "<td>" << evidence.getImageClarity() << "</td>" << "\n";
		file << "<td>" << evidence.getQuantity() << "</td>" << "\n";
		file << "<td><a href =" << evidence.getPhotograph() << ">Link</a></td>";

		file << "</tr>" << "\n";
	}

	file << "</table>" << "\n";

	file << "</body>" << "\n";

	file << "</html>" << "\n";
	file.close();

}

void HTMLlist::openInApp()
{
	const char * fileName = this->fileName.c_str();
	ShellExecuteA(NULL, NULL, "chrome.exe", fileName, NULL, SW_SHOWMAXIMIZED);
	system("PAUSE");
	 ShellExecute(NULL, "open", fileName,NULL, NULL, SW_SHOWNORMAL);

	/*std::string cmd = "open " + this->fileName;
	system(cmd.c_str());*/
}
