//This is the client address book program. Written by Nicholas Hutton and his blood, sweat, and tears on 12/7/2018
//Inspiration for UI's visual design came from the textbook


/*
If you're reading this, I did indeed submit this late. I hit a roadblock on this project on Friday the 7th after working almost all day for 2 days on it and I couldn't solve it in time.
Since I knew I would be submitting it late, i thought i would have some fun while finishing it today. That's why a lot of comments are sarcastic, silly, stupid, or references. 
Enjoy, or don't. It doesn't matter to me.
I'll give you a hint for one, how does one pronounce "Hyde and Sikh"?
*/

#include <string>
#include "contactsBinaryTree.h"
#include "contactType.h"
#include <iostream>
#include <iomanip>


using namespace std;
string first, last, phone, email;
contactsBinaryTree addressBook;
void displayUI(); //displays the main menu of the address book
void displayEditUI(); //used for the edit portion of the search function
void searchAddressBook(); //one of the main menu options -- can search for a contact, then edit it or delete it if desired
char mainUIchoice; //this determines which if statement (IE which action) the user wants the program to perform on the main menu
char editUIchoice; //this determines which if statement the user wants on the edit menu
char searchUIchoice; //this determines which if statement the user wants on the search menu
char editOrDeleteUIchoice; //this one just determines whether the program edits or deletes a contact after searching, or if it goes back to the menu
char deleteUIchoice; //this one is just for the deletion warning
int main()
{
	do
	{
		//display the UI
		displayUI();
		cin >> mainUIchoice;
		mainUIchoice = toupper(mainUIchoice); //so the program doesn't have to continuously capitalize the input if it was lowercase
		while (mainUIchoice < 'A' || mainUIchoice > 'D') //this loop makes sure the user doesn't pick a nonexistant option
		{
			cout << "Please enter a selection between A and D:";
			cin >>mainUIchoice;
			mainUIchoice = toupper(mainUIchoice);
		}
		if (mainUIchoice == 'A') //here we go, baby's first contact
			addressBook.newContact();
		else if (mainUIchoice == 'B') //The user chose... search!
			searchAddressBook();
		else if (mainUIchoice == 'C') //Time to see how many friends you have!
		{
			system("CLS"); //clears the console screen
			cout << "Address Book:\n\n";
			addressBook.display(); 
			system("pause"); 
			system("CLS"); 
		}

	} while (mainUIchoice != 'D'); //You're trapped here forever! (Unless you hit D, then I guess you get to leave)

	return 0;
}
void displayUI() //i like this menu design
{
	cout << "-------------------------------------------------------";
	cout << "\n                   Address Book Menu\n";
	cout << "-------------------------------------------------------\n";
	cout << "A) Add a new contact\n";
	cout << "B) Search for, update, or delete a contact\n";
	cout << "C) Display your contacts list in alphabetical order\n";
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
			searchUIchoice = toupper(searchUIchoice); //capitalizes the input. same reason as last time
			while (searchUIchoice < 'A' || searchUIchoice > 'B')
			{
				cout << "Please enter a selection between A and B: ";
				cin >> searchUIchoice;
				searchUIchoice = toupper(searchUIchoice);
			}
		}
	} while (!gosikh && searchUIchoice != 'B'); //this section loops as long as the user doesn't search for a contact that doesn't exist and then type the exit letter
	if (gosikh) //gooooood, it does exist
	{
		cout << "\n\n";
		gosikh->display(); //lets the user see the contact they were looking for

			cout << "What would you like to do now?\n";
			cout << "A) Edit contact\nB) Delete contact\nC) Go back\n\n";
			cin >> editOrDeleteUIchoice; //edit? delete? leave?
			editOrDeleteUIchoice = toupper(editOrDeleteUIchoice); //capitalize
			while (editOrDeleteUIchoice < 'A' || editOrDeleteUIchoice > 'C')
			{
				cout << "Please enter a selection between A and C:";
				cin >> editOrDeleteUIchoice;
				editOrDeleteUIchoice = toupper(editOrDeleteUIchoice);
			}

			if (editOrDeleteUIchoice == 'A') //edit a name. most complicated one out of all the edits
			{
				do
				{
					displayEditUI(); //another beutiful UI displayed
					cin >> editUIchoice;
					editUIchoice = toupper(editUIchoice);
					while (editUIchoice < 'A' || editUIchoice > 'D') //please only pick an option i gave you
					{
						cout << "Please enter a selection between A and D:";
						cin >> editUIchoice;
						editUIchoice = toupper(editUIchoice);
					}


					if (editUIchoice == 'A')
					{
						hyde = *gosikh; //stores the contents of the contact that was found, because...
						addressBook.remove(*gosikh); //...we're going to delete the original contact from the tree! If we don't delete it, we'll have 2 entries with the same email and phone number
						cout << "Please enter the first and last names you would like to put in instead with a space between them:\n";
						cin >> first >> last;
						hyde.setName(first, last);
						addressBook.insertNode(hyde); //we delete and replace the original contact because I don't know how I could re-sort a binary search tree


					}
					else if (editUIchoice == 'B') //oh thank god you chose an easy edit
					{
						cout << "Please enter the phone number (no parentheses/hyphens) you would like to put in instead:\n";
						cin >> phone;
						gosikh->setPhone(phone); //modifies the contact that was found to have a new phone number
					}
					else if (editUIchoice == 'C')
					{
						cout << "Please enter the email address you would like to put in instead:\n";
						cin >> email;
						gosikh->setEmail(email); //modifies the contact that was found to have a new email
					}
				} while (editUIchoice != 'D');
			}
			else if (editOrDeleteUIchoice == 'B') //DELETION TIME
			{ 
				
				cout << "Do you REALLY want to delete this contact? The contact will be lost forever.\n"; //oh i hate this part of the movie, it's so sad
				cout << "A) Yes\nB) No, go back\n\n";
				cin >> deleteUIchoice;
				deleteUIchoice = toupper(deleteUIchoice);

				while (deleteUIchoice < 'A' || deleteUIchoice > 'B')
				{
						cout << "Please enter a selection between A and B: ";
						cin >> deleteUIchoice;
						deleteUIchoice = toupper(deleteUIchoice);
				}

				if (deleteUIchoice == 'A')
				{

					addressBook.remove(*gosikh); //*sniff*, goodbye node that i searched for, you will or will not be missed

				}

			}
		//system("pause");
		system("CLS"); 
	}
}