#include "RepositoryExceptions.h"

RepositoryExceptionsInherited::RepositoryExceptionsInherited(std::string _message)
{
	this->message = _message;
}

const char* RepositoryExceptionsInherited::what() const noexcept
{
	return message.c_str();
}

void RepositoryExceptionsInherited::checkUpdate(Domain& item, std::vector<Domain> vector)
{
	std::string errors;
	if (vector.size() == 0)
		errors += "Can't update an empty repository! \n";
	bool check = false;
	for (auto& _item : vector) {
		if (item.getName() == _item.getName())
		{
			check = true;
			//errors += "Item with that name already exists! \n";
			break;
		}
	}
	if (check == false)
		errors += "Item does not exist! \n";
	if (errors.size() > 0)
		throw RepositoryExceptionsInherited(errors);
}

void RepositoryExceptionsInherited::checkDelete(std::string item, std::vector<Domain> vector)
{
	std::string errors;
	if (vector.size() == 0)
		errors += "Can't delete from an empty repository! \n";
	bool check = false;
	for (auto& _item : vector) {
		if (item == _item.getName())
		{
			check = true;
			//errors += "Item with that name already exists! \n";
			break;
		}
	}
	if (check == false)
		errors += "Item does not exist! \n";
	if (errors.size() > 0)
		throw RepositoryExceptionsInherited(errors);
}

void RepositoryExceptionsInherited::checkAdding(Domain& item, std::vector<Domain> vector)
{
	std::string errors;
	bool check = true;
	for (auto& _item : vector) {
		if (item.getName() == _item.getName())
		{
			check = false;
			errors += "Item with that name already exists! \n";
			break;
		}
	}
	if (errors.size() > 0)
		throw RepositoryExceptionsInherited(errors);
}

RepositoryExceptions::RepositoryExceptions(std::string _message)
{
	this->message = _message;
}

std::string RepositoryExceptions::getMessage() const
{
	return this->message;
}
