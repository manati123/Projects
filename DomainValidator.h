#pragma once
#include "Domain.h"
#include <exception>
#include <iostream>
#include <string>
class ValidationException {
private:
	std::string message;
public:
	ValidationException(std::string _message);
	std::string getMessage() const;
};

class ValidationExceptionInherited : public std::exception
{
private:
	std::string message;

public:
	ValidationExceptionInherited(std::string _message);
	const char* what() const noexcept override;
};

class DomainValidator {
public:
	static void validate( Domain& item);
};
