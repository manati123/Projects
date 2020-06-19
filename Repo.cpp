#include "Repo.h"
#include<algorithm>
#include<iostream>
#include "DomainValidator.h"
#include "RepositoryExceptions.h"
#include <exception>
using std::string;
void Repo::save(std::string name)
{
	for (auto& element : this->vector) {
		if (element.getName() == name) {
			bool check = true;
			for (auto& item : this->myVector)
				if (item.getName() == name)
					check = false;
			if(check)
				this->myVector.push_back(element);
		}
	}
}

Domain Repo::next()
{
	Domain item{};
	if (this->vector.size() > 0) {
		if (this->currentPosition == -1 && this->getSize() == 1)
		{
			this->currentPosition = 0;
			this->currentItem = this->vector[this->currentPosition];
			return this->currentItem;
		}
		if (this->currentPosition < this->getSize() - 1 && this->currentPosition != -1)
		{
			this->currentItem = this->vector[this->currentPosition + 1];
			this->currentPosition++;
			return this->currentItem;
		}
		else
		{
			this->currentPosition = 0;
			this->currentItem = this->vector[this->currentPosition];
			return this->currentItem;
		}
	}
	else {
		return item;
	}
}

std::vector<Domain> Repo::getMyVector()
{
	return this->myVector;
}

std::vector<Domain> Repo::getAllByMaterialAndLesserValue(std::string material, int maximumAge)
{
	std::vector<Domain> filteredVector ;
	//auto filteredVector_ToBe_Iterator = std::copy_if(this->vector.begin(), this->vector.end(),filteredVector.begin(), [material](Domain item) {return item.getName() == material; } );


	for (auto& item : this->vector) {
		if (item.getAge() < maximumAge && item.getMaterial() == material)
			filteredVector.push_back(item);
	}
	if (filteredVector.size() > 0)
		return filteredVector;
	else
		return this->vector;
}

int Repo::getCurrentPosition()
{
	return this->currentPosition;
}

int Repo::getSizeOfMyVector()
{
	return this->myVector.size();
}

bool Repo::addRepo(Domain item)
{
	try { RepositoryExceptionsInherited::checkAdding(item, this->vector);
	this->vector.push_back(item);
	return true;
	}
	catch (RepositoryExceptionsInherited exceptionThrown) {
		throw exceptionThrown;
	}
		/*for (auto& element : this->vector) {

		if (element.getName() == item.getName())
			return false;
		}
	this->vector.push_back(item);
	return true;*/
	
	
}

bool Repo::updateRepo(Domain item)
{
	/*if (this->vector.size() == 0)
		return false;
	int index = 0;*/
	
			try { RepositoryExceptionsInherited::checkUpdate(item, vector);
			for (auto& element : this->vector)
				if (element.getName() == item.getName())
				{
					element.setAge(item.getAge());
					element.setForm(item.getForm());
					element.setMaterial(item.getMaterial());
					return true;
				}
			}
			catch (RepositoryExceptionsInherited exception) {
				throw exception;
			}
			
	
	
}

bool Repo::deleteRepo(std::string name)
{
	
	const size_t size = this->vector.size();
	int index = 0;
	auto lambda = [](Domain item, std::string name) {return item.getName() == name; };
	try { RepositoryExceptionsInherited::checkDelete(name, vector);
	for (auto& element : this->vector) {
		if (element.getName() == name)
			break;
		index++;
	}
	this->vector.erase(vector.begin() + (index), vector.begin() + (index + 1));
	return size > this->vector.size();
	}
	catch (RepositoryExceptionsInherited exception) {
		throw exception;
	}
	
}

std::vector<Domain> Repo::getRepo() const
{
	return this->vector;
}

int Repo::getSize()
{
	return this->vector.size();
}