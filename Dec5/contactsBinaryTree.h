//This header and implementation are built off of IntBinaryTree.h and .cpp from the textbook and a previous lab, which we used to implement a Binary Search Tree
//Modified by Nicholas Hutton on 12/7/2018


#ifndef contactsBinaryTree_H
#define contactsBinaryTree_H

#include <iostream>
#include "contactType.h"
using namespace std;

class contactsBinaryTree
{
	private:
		struct TreeNode
		{
			contactType Contact;         // The object in the node
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};

		TreeNode *root;       // Pointer to the root node

		// Private member functions
		void insert(TreeNode *&, TreeNode *&); //actually inserts an element into the tree
		void destroySubTree(TreeNode *);
		void removeNode(contactType, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayRecursive(TreeNode *&) const; //displays the contacts list from the "smallest" to "largest". IE from leftmost node to rightmost
		contactType* searchNode(contactType, TreeNode*&); //new search function. this one returns a pointer to an object so that object can be displayed, edited, deleted
		bool searchTF(contactType); //this is the class's original boolean search function. kept around for duplicate checking

	public:
		// Constructor
		contactsBinaryTree()
		{
			root = nullptr;
		}

		// Destructor
		~contactsBinaryTree()
		{
			destroySubTree(root);
		}

		// Binary tree operations
		void insertNode(contactType); //creates a new node and calls the actual private insert function to put the node into the tree
		void remove(contactType);

		//search function. calls the private searchNode function with the contact being searched for and returns a pointer to the value in the node
		contactType* search(contactType mannequin)
		{
			return searchNode(mannequin, root);
		}

		void newContact(); //this makes a new contact in the contacts list... calls on insertNode.

		//Main display function. calls the private displayRecursive function and starts it at the root
		void display()
		{
			if (root)
				displayRecursive(root);
		}


};
#endif