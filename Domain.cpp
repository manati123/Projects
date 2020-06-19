#include "Domain.h"
#include <sstream>
#include<vector>
#include<string>
#include<string.h>

std::stringstream  Domain::toString() const
{
	std::stringstream stream;
	//std::cout << "Here I am";
	stream << this->name << " " << this->form << " " << this->age << " " << this->material << std::endl;
	return stream;
}

std::stringstream Domain::toHTML() const
{
	std::stringstream stream;
	//name -> form -> age -> material
	stream << "<tr>" << "<td>" << this->name << "</td>" << "<td>" << this->form << "</td>" << "<td>" << this->age << "</td>" << "<td>" << this->material << "</td>" << "</tr>";
	return stream;
}

std::stringstream Domain::toCSV() const
{
	std::stringstream stream;
	stream << this->name << "," << this->form << "," << this->age << "," << this->material << "\n";
	return stream;
}

std::vector<std::string> tokenize(std::string readStream, char delimiter) {
	std::vector<std::string> result;
	std::stringstream stream(readStream);
	std::string token;
	while (std::getline(stream, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

std::istream& operator>>(std::istream& instream, Domain& item)
{
	std::string line;
	std::getline(instream, line);
	std::vector<std::string> tokens = tokenize(line, ' ');
	if (tokens.size() != 4)
		return instream;
	item.name = tokens[0];
	item.material = tokens[1];
	item.age = stoi(tokens[2]);
	item.form = tokens[3];

	return instream;
}

std::ostream& operator<<(std::ostream& outstream, const Domain& item)
{
	outstream << item.toString().str();
	return outstream;
}
