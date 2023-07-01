#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor for the node class
	Node(string i, Node * l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // initializing ROOT to null
	}

	void insert(string element) //insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); //allocate memory for the new node
		newNode->info = element; //assign value to the data field of the new node
		newNode->leftchild = NULL; // make the left child of the new node poin to null
		newNode->rightchild = NULL; //make the right child of the node poin to null

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); //locate the node which will be the parent of yhe node to be inserted

		if (parent == NULL) // if the parent is NULL (tree is empty)
		{
			ROOT = newNode; //mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info) // if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode; //make the left child of the parent poin to the new node
		}
		else if (element > parent->info) //if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newNode;//make the right child of the parent point to the new node
		}
	}


	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inoder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inoder(ptr->leftchild);
			cout << ptr->info << " ";
			inoder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}
