#include "BSTree.h"
#include "BSTNode.h"

BSTree::BSTree()
{
	rootNode = nullptr;
}

BSTree::~BSTree()
{
	//implement destructor
}

int countHeight(BSTNode *start)
{
	int retd;
	if (nullptr == start)
	{
		return -1;
	}
	else
	{
		int ld = countHeight(start->getLeftChild());
		int rd = countHeight(start->getRightChild());

		return max(ld, rd) + 1;
	}
}

int BSTree::getHeight() const
{
	return countHeight(rootNode);
}

int countNodes(BSTNode *start)
{
	if (nullptr == start)
	{
		return 0;
	}
	else
	{
		return 1 + countNodes(start->getLeftChild()) + countNodes(start->getRightChild());
	}
}

int BSTree::getNumNodes() const
{
	return countNodes(rootNode);
}

void inorder(BSTNode *root, string &representation, string current)
{
	if (root == nullptr)
	{
		representation += current + ">[NULL]\n";
		return;
	}

	string leftcurrent;
	string rightcurrent;

	leftcurrent = current;
	rightcurrent = current;

	current += ">" + root->getKey() + "\n";

	representation += current;

	leftcurrent += ">l";
	inorder(root->getLeftChild(), representation, leftcurrent);

	rightcurrent += ">r";
	inorder(root->getRightChild(), representation, rightcurrent);
}

string BSTree::getRepresentation()
{
	string rep = "";
	string current = "";
	inorder(rootNode, rep, current);

	return rep;
}

BSTNode *BSTree::getNode(string key)
{
	BSTNode *tempRoot = rootNode;
	while (tempRoot != nullptr)
	{
		if (key.compare(tempRoot->getKey()) > 0)
		{
			tempRoot = tempRoot->getRightChild();
		}
		else if (key.compare(tempRoot->getKey()) < 0)
		{
			tempRoot = tempRoot->getLeftChild();
		}
		else
		{
			return tempRoot;
		}
	}
	return nullptr;
}

bool BSTree::addNode(string key)
{
	BSTNode *newNode = new BSTNode(key);
	addNode(newNode);
	return true;
}

bool BSTree::addNode(BSTNode *item)
{
	if (rootNode == nullptr)
	{
		rootNode = item;
		return true;
	}

	BSTNode *tempRoot = rootNode;
	string key = item->getKey();

	while (tempRoot != nullptr)
	{
		if (key.compare(tempRoot->getKey()) > 0)
		{
			if (tempRoot->getRightChild() == nullptr)
			{
				tempRoot->setRightChild(item);
			}
			tempRoot = tempRoot->getRightChild();
		}
		else if (key.compare(tempRoot->getKey()) < 0)
		{
			if (tempRoot->getLeftChild() == nullptr)
			{
				tempRoot->setLeftChild(item);
			}
			tempRoot = tempRoot->getLeftChild();
		}
		else
		{
			break;
		}
	}
	return true;
}