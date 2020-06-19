#pragma once
#include<string>
#include<iostream>
class Domain
{
private:
	std::string name;
	std::string material;
	std::string form;
	int age;
public:
	Domain() { this->age = -1; }
	Domain(std::string name, std::string material, int age, std::string form ) { this->name = name; this->material = material; this->form = form; this->age = age; }
	~Domain() = default;

	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setForm(std::string form) { this->form = form; }
	void setMaterial(std::string material) { this->material = material; }

	std::string getName() { return this->name; }
	std::string getForm() { return this->form; }
	std::string getMaterial() { return this->material; }
	int getAge() { return this->age; }

	std::stringstream toString() const;
	std::stringstream toHTML() const;
	std::stringstream toCSV() const;

	friend std::istream& operator>>(std::istream& instream, Domain& item);
	friend std::ostream& operator<<(std::ostream& outstream, const Domain& item);
};
