#include "contactsBinaryTree.h"

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void contactsBinaryTree::insert(TreeNode *&nodePtr, TreeNode*& newNode)
{
	if (nodePtr == nullptr)
	{
		nodePtr = newNode;
	}

	// Insert the node.
	else if (newNode->Contact < nodePtr->Contact)
	{
		insert(nodePtr->left, newNode);     // Search the left branch
	}
	else if (newNode->Contact > nodePtr->Contact)
	{
		insert(nodePtr->right, newNode);    // Search the right branch
	}
	else
	{
		delete newNode;
	}
}

//**********************************************************
// insertNode creates a new node to hold mannequin as its  *
// data and passes it to the insert function.              *
//**********************************************************

void contactsBinaryTree::insertNode(contactType mannequin)
{

	if (searchTF(mannequin)) //this is what i kept the old boolean search function for
	{
		cout << "This contact already exists.\n";
		return;
	}
	
	else 
	{
		TreeNode *newNode = nullptr;	// Pointer to a new node.

	   // Create a new node and store num in it.
		newNode = new TreeNode;
		newNode->Contact = mannequin;
		newNode->left = newNode->right = nullptr;

		// Insert the node.
		insert(root, newNode);
	}
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void contactsBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//*************************************************************************
// searchTF (TF --> "True"/"False") determines if a value is present in   *
// the tree. If so, the function returns true.							  *
// Otherwise, it returns false.                                           *
//*************************************************************************
bool contactsBinaryTree::searchTF(contactType mannequin)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->Contact == mannequin)
			return true;
		else if (mannequin < nodePtr->Contact)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

contactType* contactsBinaryTree::searchNode(contactType mannequin, TreeNode*& nodeCurrent)
{
	//checks if nodeCurrent even points to anything, returns nullptr if it doesn't
	if (nodeCurrent == nullptr)
	{
		return nullptr;
	}
	//returns a pointer to nodeCurrent->Contact if it contains what the program's looking for
	else if (mannequin == nodeCurrent->Contact)
	{
		return &(nodeCurrent->Contact);
	}
	//if the mannequin is less than the nodeCurrent->Contact, then if the value being searched for exists, it'll be in the left subtree, so calls itself to run again on the left subtree
	else if (mannequin < nodeCurrent->Contact)
	{
		return searchNode(mannequin, nodeCurrent->left);
	}
	//if the mannequin is greater than the nodeCurrent->Contact, then if the value being searched for exists, it'll be in the right subtree, so calls itself to run again on the right subtree
	else if (mannequin > nodeCurrent->Contact)
	{
		return searchNode(mannequin, nodeCurrent->right);
	}
}

//******************************************************
// remove calls deleteNode to delete the			   *
// node whose Contact member is the same as mannequin. *
//******************************************************

void contactsBinaryTree::remove(contactType mannequin)
{
	removeNode(mannequin, root);
}

void contactsBinaryTree::newContact()
{
	string f, l, p, e; 
	cout << "\nWhat is your contact's information?\n";
	cout << "Please type their name, phone number (without hyphens or parentheses), and email, with a space between each:\n";
	cin >> f >> l >> p >> e;
	contactType doll(f, l, p, e); //f,l,p, and e equate to firstName, lastName, phone, and email
	insertNode(doll); //attempt to insert this new contact
}

//********************************************
// removeNode deletes the node whose Contact *
// member is the same as mannequin.          *
//********************************************

void contactsBinaryTree::removeNode(contactType mannequin, TreeNode*& nodePtr)
{
	//why are you trying to delete a something at a null pointer, there's nothing there
	if (!nodePtr)
	{
		return;
	}
	//if nodePtr->Contact is the same as mannequin, then congratulation, you done found it, delete nodePtr
	else if (mannequin == nodePtr->Contact)
	{
		makeDeletion(nodePtr);
	}
	//if mannequin is smaller than nodePtr->Contact, durrhhh i dunno boss, go to the left subtree i guess
	else if (mannequin < nodePtr->Contact)
	{
		removeNode(mannequin, nodePtr->left);
	}
	//if mannequin is bigger than nodePtr->Contact, durrhhh i dunno boss, go to the right subtree i guess
	else
	{
		removeNode(mannequin, nodePtr->right);
	}
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void contactsBinaryTree::makeDeletion(TreeNode*& nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode* tempNodePtr = nullptr;

	if (nodePtr == nullptr) //error, node doesnt exist
	{
		throw 0;
	}
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//Displays the entire list of contacts in the proper order
void contactsBinaryTree::displayRecursive(TreeNode*& nodePtr) const
{
	if (nodePtr->left)
	{
		displayRecursive(nodePtr->left);
	}
		nodePtr->Contact.display();
		cout << "\n";
	if (nodePtr->right)
	{
		displayRecursive(nodePtr->right);
	}
}
