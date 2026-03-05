#pragma once
#include <string>

class Person
{
public:
	enum Sex { UNDEF, MALE, FEMALE };
private:
	std::string name;
	int age;
	Sex sex;
public:
	Person(std::string n, int a, Sex sex);
	Person(std::string n, int a);
	Person(std::string n, Sex s);
	Person(std::string n);
	Person(int a);
	Person(Sex sex);
	Person();

	std::string GetName();
	int GetAge();
	Sex GetSex();
};

