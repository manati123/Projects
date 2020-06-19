#include "FileRepo.h"
#include <sstream>
#include<fstream>
//#include <qdebug.h>

void FileRepo::write(std::vector<Domain> vector, std::string name)
{
	std::ofstream file(name);
	for (auto& item : vector)
		file << item.toString().str();
	file.close();
}

void FileRepo::writeCSV(std::vector<Domain> vector, std::string name)
{
	std::ofstream file(name);
	for (auto& item : vector)
		file << item.toCSV().str();
	file.close();
}

void FileRepo::writeHTML(std::vector<Domain> vector, std::string name)
{
	std::ofstream file(name);//write simple, then append with the new stuff
	file << "<!DOCTYPE html> \n <html> \n	<head>\n		<title>MyList</title>\n		</head>\n	<body>\n		<table border=1>\n			<tr><td>Name</td><td>Form</td><td>Age</td><td>Material</td></tr>";
	file.close();
	std::ofstream fileAppender(name, std::ios::app);
	for (auto& item : vector)
		fileAppender << item.toHTML().str();
	fileAppender << "		</table> \n" << "	</body> \n" << "</html>";
	fileAppender.close();
}

std::vector<Domain> FileRepo::readFromCSV(std::string filename)
{
	std::vector<Domain> vector;
	std::ifstream fileReader(filename);
	Domain item{};
	while (fileReader >> item) {
		vector.push_back(item);
	}
	fileReader.close();
	return vector;
}

std::vector<Domain> FileRepo::readFromHTML(std::string filename)
{
	std::vector<Domain> vector;
	std::ifstream fileReader(filename);
	Domain item{};
	while (fileReader >> item) {
		vector.push_back(item);
	}
	fileReader.close();
	return vector;
}

std::vector<Domain> FileRepo::read(std::string filename)
{
	std::vector<Domain> vector;
	std::ifstream fileREader(filename);
	Domain item{};
	while (fileREader >> item) {
		//qDebug() << QString::fromStdString(item.getName());
		vector.push_back(item);
	}
	fileREader.close();
	return vector;
}
