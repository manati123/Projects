#pragma once
#include "Repo.h"
#include "Domain.h"
#include "FileRepo.h"
#include "Undo.h"
#include <stack>

class Service
{
private:
	Repo& repo;
	FileRepo& fileRepo;
	std::vector<std::shared_ptr<Undo>> undos;
	std::vector<std::shared_ptr<Undo>> redos;
	/*std::vector<std::shared_ptr<Undo>> undos;
	std::vector<std::shared_ptr<Undo>> redos;*/
public:
	Service(Repo& newRepo, FileRepo& newFileRepo) : repo{ newRepo }, fileRepo{ newFileRepo } {};
	~Service() = default;
	void saveService(std::string name);
	Domain nextService();
	std::vector<Domain> getMyVectorService();
	std::vector<Domain> getAllByMaterialAndLesserValueService(std::string material, int maximumAge);
	int getCurrentPositionService();
	int getSizeOfMyVectorService();
	bool addService(std::string name, std::string form, std::string material, int age);
	bool updateService(std::string name, std::string form, std::string material, int age);
	bool deleteService(std::string name);
	std::vector<Domain> getRepoService();
	int getSizeOfRepo();
	void readFromFile(std::string fileName);
	void writeToFile(std::string fileName);
	void writeToCSV(std::string fileName);
	void writeToHTML(std::string fileName);
	void undo();
	void redo();




};





