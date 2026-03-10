#include "Person.h"
#include <string>

Person::Person(std::string n, int a, Sex s) : 
	name{ n }, age{ a }, sex{ s }
{
	if (name.empty())
		name = "NoName";

	if (name.size() > 40)
		name.erase(name.begin() + 40, name.end());

	if (age <= 0 || age > 100)
		age = 0;

	if (sex < UNDEF || sex > FEMALE)
		sex = UNDEF;
}

Person::Person(std::string n, int a) : Person(n, a, Person::UNDEF)
{
}

Person::Person(std::string n, Sex s) : Person(n, 0, s)
{
}

Person::Person(std::string n) : Person(n, 0, Person::UNDEF)
{
}

Person::Person(int a) : Person("NoName", a, Person::UNDEF)
{
}

Person::Person(Sex s) : Person("NoName", 0, s)
{
}

Person::Person() : Person("NoName", 0, Person::UNDEF)
{
}

std::string Person::GetName()
{
	return name;
}

int Person::GetAge()
{
	return age;
}

Person::Sex Person::GetSex()
{
	return sex;
}