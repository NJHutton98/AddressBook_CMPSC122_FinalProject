#include "contactType.h"



//Mutators
void contactType::setFirst(const string& newf)
{
	firstName = newf;
}

void contactType::setLast(const string& newl)
{
	lastName = newl;
}

void contactType::setName(const string& newf, const string& newl)
{
	firstName = newf;
	lastName = newl;
}

void contactType::setPhone(const string& newp)
{
	phone = newp;
}

void contactType::setEmail(const string& newe)
{
	email = newe;
}

void contactType::display()
{
	cout << "Name: " << firstName << " " << lastName << "\n";
	cout << "Phone Number: " << phone << "\n";
	cout << "Email Address: " << email << "\n\n";

}

//overloaded binary ops
bool contactType::operator<(const contactType&right) //we're sorting by last name so in all of these, we start with the last name first
{
	if (lastName > right.lastName)
		return false;
	else if (lastName == right.lastName)
	{
		if (firstName > right.firstName)
			return false;
		else
			return true;
	}
	else
		return true;
}

bool contactType::operator>(const contactType&right)
{
	if (lastName < right.lastName)
		return false;
	else if (lastName == right.lastName)
	{
		if (firstName < right.firstName)
			return false;
		else
			return true;
	}
	else
		return true;
}

bool contactType::operator==(const contactType &right)
{
	//If all private data members are equivalent, return true
	if (lastName == right.lastName && firstName == right.firstName)
		return true;
	//If not, return false
	else
		return false;
}

bool contactType::operator!=(const contactType &right)
{
	//If all private data members are inequivalent, return true
	if (lastName != right.lastName)
		return true;
	else if (firstName != right.firstName)
		return true;
	//If not, return false
	else
		return false;
}
