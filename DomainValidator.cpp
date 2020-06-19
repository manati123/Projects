#include "DomainValidator.h"
#include <regex>
using namespace std;

ValidationException::ValidationException(std::string _message) : message{_message}{}

std::string ValidationException::getMessage() const {
	return this->message;
}

ValidationExceptionInherited::ValidationExceptionInherited(std::string _message) : message{ _message } {}

const char* ValidationExceptionInherited::what() const noexcept {
	return message.c_str();
}

bool isNumber(std::string string) {
	std::regex expression("^-?\\d+");
	if (std::regex_match(string, expression)) 
		return true;
	else 
		return false;
}


void DomainValidator::validate( Domain& item) {
	std::string errors;
	if (isNumber(item.getName()) == true || isNumber(item.getMaterial()) == true || isNumber(item.getForm()) == true)
		errors += string("The name/form/material should be strings not integers!\n");
	if (item.getAge() < 0)
		errors += string("Age should be positive!");

	if (errors.size() > 0)
		throw ValidationExceptionInherited(errors);
	
}