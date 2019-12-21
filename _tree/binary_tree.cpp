#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node 
{
	int data;
	Node *left, *right, *parent;
	int height;
	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		height = 1;
	}
}

Node *findPredeccessor(Node *);

Node *insertTree(Node *, int, Node *);
Node *deleteTreeByMerging(Node *, int);
Node *deleteTreeByCopying(Node *, int);

void inOrder(Node *);
void preOrder(Node *);
void postOrder(Node *);
void levelOrder(Node *);

int main()
{
	
	return 0;
}

Node *findPredeccessor(Node *node)
{
	if (node->right == NULL)
	{
		return node;
	}
	else
	{
		return findPredeccessor(node->right);
	}
}

Node *insertTree(Node *node, int x, Node *parent)
{
	if (node == NULL)
	{
		Node *new_node = new Node(data);
		if (parent == NULL)
		{
			new_node->parent = NULL;
		}
		else
		{
			new_node->parent = parent;
		}
		return new_node;
	}
	else if (x < node->data)
	{
		return insertTree(node->left, x, node);
	}
	else if (x > node->data)
	{
		return insertTree(node->right, x, node);
	}
	else
	{
		cout << "Data cannot be duplicated!\n";
	}
}

Node *deleteTreeByMerging(Node *, int)
{
	
}

Node *deleteTreeByCopying(Node *, int)
{
	
}

void inOrder(Node *);
void preOrder(Node *);
void postOrder(Node *);
void levelOrder(Node *);
