#pragma once
#include "Domain.h"
#include "Repo.h"
#include <fstream>

class FileRepo : public Repo {
public:
	void write(std::vector<Domain> vector, std::string name);
	void writeCSV(std::vector<Domain> vector, std::string name);
	void writeHTML(std::vector<Domain> vector, std::string name);
	std::vector<Domain> readFromCSV(std::string filename);
	std::vector<Domain> readFromHTML(std::string filename);
	std::vector<Domain> read(std::string filename);
	

};