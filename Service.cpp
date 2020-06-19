#include "Service.h"
#include <vector>
#include <algorithm>
#include "DomainValidator.h"
//#include "..\..\..\..\source\repos\TheLastStand\Service.h"

void Service::saveService(std::string name)
{
	this->repo.save(name);
}

Domain Service::nextService()
{
	return this->repo.next();
}

std::vector<Domain> Service::getMyVectorService()
{
	return this->repo.getMyVector();
}

std::vector<Domain> Service::getAllByMaterialAndLesserValueService(std::string material, int maximumAge)
{
	return this->repo.getAllByMaterialAndLesserValue(material, maximumAge);
}

int Service::getCurrentPositionService()
{
	return this->repo.getCurrentPosition();
}

int Service::getSizeOfMyVectorService()
{
	return this->repo.getSizeOfMyVector();
}

bool Service::addService(std::string name, std::string form, std::string material, int age)
{
		//qInfo() << "Biciz";
	try {

		//QMessageBox box;
		Domain item{ name,material, age,form };
	//	box.setText(QString::fromStdString(item.getName()));
		//box.exec();
		DomainValidator::validate(item);
		undos.push_back(std::make_shared<AddUndo>(repo, item));
		redos.push_back(std::make_shared<DeleteUndo>(repo, item));
		return this->repo.addRepo(item);
	}
	catch (ValidationExceptionInherited exception) {

		throw exception;
	}
}

bool Service::updateService(std::string name, std::string form, std::string material, int age)
{
	try {
		Domain item{ name,material, age,form };
		DomainValidator::validate(item);
		Domain oldItem;
		for(auto& repoItem : this->getRepoService())
			if (repoItem.getName() == name) {
				oldItem = repoItem;
				}
		undos.push_back(std::make_shared<UpdateUndo>(repo, oldItem));
		redos.push_back(std::make_shared<UpdateUndo>(repo, item));
		return this->repo.updateRepo(item);
	}
	catch (ValidationExceptionInherited exception) {

		throw exception;
	}
}

bool Service::deleteService(std::string name)
{
	//Undo* operation = new AddUndo{ repo,Domain{name,"",-1,""} };
	//this->undos.push_back(operation);
	Domain oldItem;
	for (auto& repoItem : this->getRepoService())
		if (repoItem.getName() == name) {
			oldItem = repoItem;
		}
	undos.push_back(std::make_shared<AddUndo>(repo, oldItem));
	undos.push_back(std::make_shared<DeleteUndo>(repo, oldItem));
	return this->repo.deleteRepo(name);
}

std::vector<Domain> Service::getRepoService()
{
	return this->repo.getRepo();
}

int Service::getSizeOfRepo()
{
	return this->repo.getSize();
}

void Service::readFromFile(std::string fileName)
{
	std::vector<Domain> vector = this->fileRepo.read(fileName);
	for (auto& item : vector) {
		
		this->addService(item.getName(), item.getForm(), item.getMaterial(), item.getAge());
	}
	
}

void Service::writeToFile(std::string name)
{
	this->fileRepo.write(this->getRepoService(), name);
}

void Service::writeToCSV(std::string fileName)
{
	this->fileRepo.writeCSV(this->getMyVectorService(), fileName);
}

void Service::writeToHTML(std::string fileName)
{
	this->fileRepo.writeHTML(this->getMyVectorService(), fileName);
}

void Service::undo()
{
	if (undos.empty()) {
		return;
	}
	undos.back()->do_undo();
	//undos.back().~shared_ptr();
	undos.pop_back();
	//std::cout << "Here";
}

void Service::redo()
{
	if (redos.empty()) {
		return;
	}
	/*while (!redos.empty()) {
		redos.back().~shared_ptr();
		redos.erase(redos.end() - 1, redos.end());
	}*/
	redos.back()->do_undo();
	//redos.back().~shared_ptr();
	//redos.erase(redos.end() - 1, redos.end());
}


