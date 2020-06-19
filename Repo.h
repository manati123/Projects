#pragma once
#include"Domain.h"
#include<vector>
#include<string>
#include<iostream>
class Repo
{
private:
	std::vector<Domain> vector;
	std::vector<Domain> myVector;
	Domain currentItem;
	int currentPosition;
public:
	void save(std::string name);
	Domain next();
	std::vector<Domain> getMyVector();
	std::vector<Domain> getAllByMaterialAndLesserValue(std::string material, int maximumAge);
	int getCurrentPosition();
	int getSizeOfMyVector();
	Domain operator[](int index) { return this->vector[index]; }
	Repo() { this->currentPosition = -1; }
	bool addRepo(Domain item);
	bool updateRepo(Domain item);
	bool deleteRepo(std::string name);
	std::vector<Domain> getRepo() const;
	int getSize();
	~Repo() = default;
};
