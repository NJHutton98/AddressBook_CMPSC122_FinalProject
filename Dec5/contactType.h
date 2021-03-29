//Simple contact class written by Nicholas Hutton on 12/7/2018

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class contactType
{
	private:
		string firstName;
		string lastName;
		string phone; //i store the phone number as a string because we're not doing any math with it. also the user can choose to enter it however they choose
		string email;
	public:
		
		contactType()	//default constructor
		{
			firstName = "";
			lastName = "";
			phone = "";
			email = "";
		}
				
		contactType(string f, string l, string p, string e)	//constructor
		{
			firstName = f;
			lastName = l;
			phone = p;
			email = e;
		}

		//allows filthy peasants outside this class to have the name, phone number, and email of the object in question
		string getFirst() const 
		{
			return firstName;
		}

		string getLast() const
		{
			return lastName;
		}

		string getPhone() const
		{
			return phone;
		}

		string getEmail() const
		{
			return email;
		}

		//Mutators
		void setFirst(const string&);
		void setLast(const string&);
		void setName(const string&, const string&); //shortcut to edit the name
		void setPhone(const string&);
		void setEmail(const string&);

		void display(); //display function

		//Binary relations oveloads
		bool operator <(const contactType&);
		bool operator >(const contactType&);
		bool operator ==(const contactType&);
		bool operator !=(const contactType&);
};

#endif