#include "contactsList.h"

void contactsList::newContact()
{
	string f, l, p, e;
	cout << "\nWhat is your contact's information?\n";
	cout << "Please type their name, phone number (without hyphens or parentheses), and email, with a space between each:\n";
	cin >> f >> l >> p >> e;
	contactType doll(f, l, p, e);
	Contact.push_back(doll);
}

void contactsList::editContactByName(string f, string l, string newf, string newl)
{
	
}

void contactsList::editContactByPhone(string p, string newp)
{
}

void contactsList::editContactByEmail(string e, string newe)
{
}
