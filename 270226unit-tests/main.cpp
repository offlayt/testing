#include <iostream>
#include "../1_test-module/Person.h"

using namespace std;


int main()
{
	Person p("Oleg", 28, Person::MALE);

cout << p.GetName() << endl;
}