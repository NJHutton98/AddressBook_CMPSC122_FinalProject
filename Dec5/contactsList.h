#ifndef contactsList_H
#define contactsList_H
#include "contactType.h"
#include <iostream>
using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************


class ListNode
{
public:
	contactType Contact;           // Node value
	ListNode *next; // Pointer to the next node

	// Constructor
	ListNode(contactType nodeValue)
	{
		Contact = nodeValue;
		next = nullptr;
	}
};

//*********************************************
// LinkedList class                           *
//*********************************************


class LinkedList
{
private:
	ListNode *head;   // List head pointer

public:
	// Constructor
	LinkedList()
	{
		head = nullptr;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(contactType);
	void insertNode(contactType);
	void deleteNode(contactType);
	void displayList() const;
	bool searchNode(contactType);
};


//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************


void LinkedList::appendNode(contactType mannequin)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store newValue there.
	newNode = new ListNode(mannequin);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************


void LinkedList::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		nodePtr->Contact.display();

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************


void LinkedList::insertNode(contactType newValue)
{
	ListNode *newNode;				// A new node
	ListNode *nodePtr;				// To traverse the list
	ListNode *previousNode = nullptr; // The previous node

	// Allocate a new node and store newValue there.
	newNode = new ListNode(newValue);

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->Contact < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************


void LinkedList::deleteNode(contactType searchValue)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->Contact == searchValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->Contact != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************


LinkedList::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

//*****************************************************
// The searchNode function searches for a node        *
// with searchValue as its value. If it is found,	  *
// the function returns true.				          *
//*****************************************************

bool LinkedList::searchNode(contactType searchValue)
{
	ListNode *nodePtr;       // To traverse the list

								// If the list is empty, do nothing.
	if (!head)
		return 0;

	// Determine if the first node is the one.
	if (head->Contact == searchValue)
	{
		nodePtr = head->next;
		return 1;

	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is not equal to what's being searched for.
		while (nodePtr != nullptr && nodePtr->Contact != searchValue)
		{
			nodePtr = nodePtr->next;
		}

		// If nodePtr is found while looping, return that its value is found
		if (nodePtr->Contact == searchValue)
		{
			return 1;
		}
	}
	return 0;
}
#endif