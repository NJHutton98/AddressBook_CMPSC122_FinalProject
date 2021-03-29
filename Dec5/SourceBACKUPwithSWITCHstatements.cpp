//This is the client address book program. Written by Nicholas Hutton and his blood, sweat, and tears on 12/7/2018
//Inspiration for UI's visual design came from the textbook
#include <string>
#include "contactsBinaryTree.h"
#include "contactType.h"
#include <iostream>
#include <iomanip>


using namespace std;
string first, last, phone, email;
contactsBinaryTree addressBook;
void displayUI();
void displayEditUI();
void displaySearchUI();
void searchAddressBook();
char mainUIchoice;
char editUIchoice;
char searchUIchoice;
char editOrDeleteUIchoice;
char deleteUIchoice;
int main()
{
	do
	{
		//display the UI
		displayUI();
		cin >> mainUIchoice;
		while (toupper(mainUIchoice) < 'A' || toupper(mainUIchoice) > 'D')
		{
			cout << "Please enter a selection between A and D:";
			cin >>mainUIchoice;
		}
		switch (mainUIchoice)
		{
		case 'a':
		case 'A':
			addressBook.newContact(); break;
		/*case 'b':
		case 'B': 
			cout << "\nEnter the name of the contact you would like to remove:\n";
			cin >> first >> last;
			addressBook.deleteContact(first, last); break;
*/
		//case 'c':
		//case 'C':
		//	
			//do
			//{
			//	displayEditUI();
			//	cin >> editUIchoice;
			//	while (toupper(editUIchoice) < 'A' || toupper(editUIchoice) > 'D')
			//	{
			//		cout << "Please enter a selection between A and D:";
			//		cin >> editUIchoice;
			//	}
			//	switch (editUIchoice)
			//	{
			//	case 'a':
			//	case 'A':
			//		cout << "Please enter the first and last names of the contact you would like to edit with a space between them:\n";
			//		cin >> first >> last;
			//		cout << "Please enter the first and last names you would like to put in instead with a space between them:\n";
			//		cin >> first >> last;
			//		//addressBook.editContactByName(f, l, newf, newl); 
			//		break;

			//	case 'b':
			//	case 'B':
			//		cout << "Please enter the phone number (no parentheses/hyphens) of the contact you would like to edit:\n";
			//		//cin >> p;
			//		cout << "Please enter the phone number (no parentheses/hyphens) you would like to put in instead:\n";
			//		//cin >> newp;
			//		//addressBook.editContactByPhone(p, newp); break;
			//	case 'c':
			//	case 'C':
			//		cout << "Please enter the email address of the contact you would like to edit:\n";
			//		//cin >> e;
			//		cout << "Please enter the email address you would like to put in instead:\n";
			//		//cin >> newe;
			//		//addressBook.editContactByEmail(e, newe); break;
			//	} break;
			//} while (toupper(editUIchoice) != 'D'); 
		//	

		////case 'd':
		////case 'D':
		////	
		case 'b':
		case 'B':
			searchAddressBook(); break;
		case 'c':
		case 'C':
			system("CLS");
			cout << "Address Book:\n\n";
			addressBook.display(); 
			system("pause"); 
			system("CLS"); break;
		}

	} while (toupper(mainUIchoice) != 'D');




	//contactType test("Nicholas", "Hutton", "7176591531", "njhutton@comcast.net");
	//contactType test2("Nicholas", "Hutton", "8005882300", "nick.fink98@gmail.com");
	//test.display();
	//test2.display();
	//if (test2 == test)
	//	cout << "yeehaw";
	//else
	//	cout << "sad day";
	//string s, t;
	//cout << "Enter a new name for test2\n";
	//cin >> s >> t;
	////test2.editContactName(s, t);
	////test2.display();
	////string q;
	////cout << "Enter a new phone number for test\n";
	////cin >> q;
	////test.editContactPhone(q);
	////test.display();
	////cout << "Enter a new email address for test2\n";
	////cin >> q;
	////test2.editContactEmail(q);
	////test2.display();
	//vector<contactType> Contacts;
	//Contacts.push_back(test);
	//test.editContactName(s, t);
	//test.display();
	//Contacts[0].display();

	return 0;
}
void displayUI()
{

	cout << "-------------------------------------------------------";
	cout << "\n                   Address Book Menu\n";
	cout << "-------------------------------------------------------\n";
	cout << "A) Add a new contact\n";
	cout << "B) Search for, update, or delete a contact\n";
	//cout << "C) Update a contact's information\n";
	cout << "C) Display your contacts list in alphabetical order\n";
	//cout << "E) Search for a contact in your address book\n";
	cout << "D) Exit the address book program\n\n";
	cout << "Please enter your choice between A and D: ";
}
void displayEditUI()
{
	cout << "-------------------------------------------------------";
	cout << "\n                   Contact Edit Menu\n";
	cout << "-------------------------------------------------------\n";
	cout << "A) Update the contact's name\n";
	cout << "B) Update the contact's phone number\n";
	cout << "C) Update the contact's email address\n";
	cout << "D) Go back\n";
	cout << "Please enter your choice between A and D: ";
}

void searchAddressBook()
{
	contactType hyde;	//this temporary contact stores contact info
	contactType *gosikh;	//this pointer points to the contact when it's found
	do
	{
		system("CLS");
		cout << "Please enter the name of the contact you want to look for:\n";
		cin >> first >> last;
		hyde.setName(first, last); //sets up the contact being searched for
		gosikh = addressBook.search(hyde); //COMMENCE SEARCH OPERATION

		if (!gosikh) //if the search function returns a nullPtr ---- Means contact doesn't exist
		{
			system("CLS");
			cout << "So, you've tried to search for a contact that doesn't exist.\nWould you like to try again?\n";
			cout << "A) Yes\nB) No\n\n";
			cin >> searchUIchoice;
			while (toupper(searchUIchoice) < 'A' || toupper(searchUIchoice) > 'B')
			{
				cout << "Please enter a selection between A and B: ";
				cin >> searchUIchoice;
			}
		}
	} while (!gosikh && toupper(searchUIchoice) != 'B');
	if (gosikh)
	{
		cout << "\n\n";
		gosikh->display();
		do
		{
			cout << "What would you like to do now?\n";
			cout << "A) Edit contact\nB) Delete contact\nC) Go back\n\n";
			cin >> editOrDeleteUIchoice;
			while (toupper(editOrDeleteUIchoice) < 'A' || toupper(editOrDeleteUIchoice) > 'C')
			{
				cout << "Please enter a selection between A and C:";
				cin >> editOrDeleteUIchoice;
			}
			switch (editOrDeleteUIchoice)
			{
				case 'a':
				case 'A':
					do
					{
						displayEditUI();
						cin >> editUIchoice;
						while (toupper(editUIchoice) < 'A' || toupper(editUIchoice) > 'D')
						{
							cout << "Please enter a selection between A and D:";
							cin >> editUIchoice;
						}
						switch (editUIchoice)
						{
						case 'a':
						case 'A':
							hyde = *gosikh;
							addressBook.remove(*gosikh);
							cout << "Please enter the first and last names you would like to put in instead with a space between them:\n";
							cin >> first >> last;
							hyde.setName(first, last);

							try
							{
								addressBook.insertNode(hyde);
							}
							catch (int a)
							{
								cout << "\nHey there, it seems that this contact already exists.\n";
							}
							break;

						case 'b':
						case 'B':
							cout << "Please enter the phone number (no parentheses/hyphens) you would like to put in instead:\n";
							cin >> phone;
							gosikh->setPhone(phone); break;
						case 'c':
						case 'C':
							cout << "Please enter the email address you would like to put in instead:\n";
							cin >> email;
							gosikh->setEmail(email); break;
						} break;
					} while (toupper(editUIchoice) != 'D'); break;

				case 'b':
				case 'B':
					do
					{
						cout << "Do you REALLY want to delete this contact? The contact will be sent to a farm upstate where it can play with lots of other contacts.\n";
						cout << "A) Yes\nB) No, go back\n\n";
						cin >> deleteUIchoice;
						while (toupper(deleteUIchoice) < 'A' || toupper(deleteUIchoice) > 'B')
						{
							cout << "Please enter a selection between A and B: ";
							cin >> deleteUIchoice;
						}
						if (toupper(deleteUIchoice) == 'A')
						{
							addressBook.remove(*gosikh);
						}
					} while (toupper(deleteUIchoice) != 'B'); break;
			}
		} while (toupper(editOrDeleteUIchoice) != 'C');
		
		system("pause");
		system("CLS"); 
	}
}