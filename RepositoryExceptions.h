#pragma once
#include <iostream>
#include <string>
#include "Domain.h"
#include <vector>
class RepositoryExceptions
{
private:
	std::string message;
public:
	RepositoryExceptions(std::string _message);
	std::string getMessage() const;
};

class RepositoryExceptionsInherited : public std::exception {
private:
	std::string message;
public:
	RepositoryExceptionsInherited(std::string _message);
	const char* what() const noexcept override;
	static void checkUpdate(Domain& item, std::vector<Domain> vector);
	static void checkDelete(std::string item, std::vector<Domain> vector);
	static void checkAdding(Domain& item, std::vector<Domain> vector);
};



