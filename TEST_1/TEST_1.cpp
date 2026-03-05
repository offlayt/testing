#include "pch.h"
#include "CppUnitTest.h"
#include "../1_test-module/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TEST1
{
	TEST_CLASS(MODULE_1_PERSON)
	{
	public:
		TEST_METHOD(MAX_LENGTH_NAME)
		{
			std::string name(50, 'a');
			Person person{ name };
			std::string expected(40, 'a');
			Assert::AreEqual(expected, person.GetName());
		}

		TEST_METHOD(NORMAL_NAME)
		{
			std::string name = "Oleg";
			Person person{ name };
			Assert::AreEqual(name, person.GetName());
		}

		TEST_METHOD(NAME_EMPTY_NONAME)
		{
			std::string name = "";
			Person person{ name };
			std::string expected = "NoName";
			Assert::AreEqual(expected, person.GetName());
		}

		TEST_METHOD(AGE_NEGATIVE)
		{
			Person person{ "Test", -5, Person::MALE };
			Assert::AreEqual(0, person.GetAge());
		}

		TEST_METHOD(AGE_ZERO)
		{
			Person person{ "Test", 0, Person::MALE };
			Assert::AreEqual(0, person.GetAge());
		}

		TEST_METHOD(AGE_OVER_100)
		{
			Person person{ "Test", 150, Person::MALE };
			Assert::AreEqual(0, person.GetAge());
		}

		TEST_METHOD(AGE_VALID)
		{
			Person person{ "Test", 25, Person::MALE };
			Assert::AreEqual(25, person.GetAge());
		}

		TEST_METHOD(SEX_UNDEF)
		{
			Person person{ "Test", 20 };
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(SEX_MALE)
		{
			Person person{ "Test", 20, Person::MALE };
			Assert::AreEqual(Person::MALE, person.GetSex());
		}

		TEST_METHOD(SEX_FEMALE)
		{
			Person person{ "Test", 20, Person::FEMALE };
			Assert::AreEqual(Person::FEMALE, person.GetSex());
		}

		TEST_METHOD(SEX_INVALID)
		{
			Person person{ "Test", 20, static_cast<Person::Sex>(5) };
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(CONSTRUCTOR_NAME_AGE)
		{
			Person person{ "Alice", 30 };
			Assert::AreEqual(std::string("Alice"), person.GetName());
			Assert::AreEqual(30, person.GetAge());
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(CONSTRUCTOR_NAME_SEX)
		{
			Person person{ "Bob", Person::MALE };
			Assert::AreEqual(std::string("Bob"), person.GetName());
			Assert::AreEqual(0, person.GetAge());
			Assert::AreEqual(Person::MALE, person.GetSex());
		}

		TEST_METHOD(CONSTRUCTOR_AGE_ONLY)
		{
			Person person{ 35 };
			Assert::AreEqual(std::string("NoName"), person.GetName());
			Assert::AreEqual(35, person.GetAge());
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(CONSTRUCTOR_SEX_ONLY)
		{
			Person person{ Person::FEMALE };
			Assert::AreEqual(std::string("NoName"), person.GetName());
			Assert::AreEqual(0, person.GetAge());
			Assert::AreEqual(Person::FEMALE, person.GetSex());
		}

		TEST_METHOD(CONSTRUCTOR_DEFAULT)
		{
			Person person;
			Assert::AreEqual(std::string("NoName"), person.GetName());
			Assert::AreEqual(0, person.GetAge());
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(NAME_EXACT_40)
		{
			std::string name(40, 'b');
			Person person{ name };
			Assert::AreEqual(40, (int)person.GetName().size());
		}

		TEST_METHOD(NAME_EXACT_41)
		{
			std::string name(41, 'c');
			Person person{ name };
			Assert::AreEqual(40, (int)person.GetName().size());
		}

		TEST_METHOD(AGE_1)
		{
			Person person{ "Test", 1, Person::MALE };
			Assert::AreEqual(1, person.GetAge());
		}

		TEST_METHOD(AGE_100)
		{
			Person person{ "Test", 100, Person::MALE };
			Assert::AreEqual(100, person.GetAge());
		}

		TEST_METHOD(SEX_NEGATIVE)
		{
			Person person{ "Test", 20, static_cast<Person::Sex>(-1) };
			Assert::AreEqual(Person::UNDEF, person.GetSex());
		}

		TEST_METHOD(FULL_CONSTRUCTOR_ALL_FIELDS)
		{
			Person person{ "John", 45, Person::MALE };
			Assert::AreEqual(std::string("John"), person.GetName());
			Assert::AreEqual(45, person.GetAge());
			Assert::AreEqual(Person::MALE, person.GetSex());
		}
	};
}
