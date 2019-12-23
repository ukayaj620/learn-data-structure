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
};

Node *searchNode(Node *, int);
Node *findPredeccessor(Node *);

Node *insertTree(Node *, int, Node *);
Node *deleteTreeByMerging(Node *, int);
Node *deleteTreeByCopying(Node *, int);

void inOrder(Node *);
void preOrder(Node *);
void postOrder(Node *);

int heightTree(Node *);
void printGivenLevel(Node *, int);
void levelOrder(Node *);

int main()
{
	Node *root = NULL;
	int pil;
	
	do
	{
		system("CLS");
		cout << "|BINARY TREE|\n"
			<< "1. Insert Data\n"
			<< "2. Delete Data by Merging\n"
			<< "3. Delete Data by Copying\n"
			<< "4. Search Node\n"
			<< "5. Display Tree\n6. Exit\nYour Choice: ";
		cin >> pil;
		
		switch(pil)
		{
			case 1: {
				int x;
            	cout << "Data?: "; cin >> x;
         		root = insertTree(root,x,NULL);
				break;
			}
			case 2: {
				int x;
            	cout << "Deleted Data?: "; cin >> x;
            	root = deleteTreeByMerging(root,x);
				break;
			}
			case 3: {
				int x;
            	cout << "Deleted Data?: "; cin >> x;
            	root = deleteTreeByCopying(root,x);
				break;
			}
			case 4: {
				int x;
				cout << "Searched Data?: "; cin >> x;
				Node *node = searchNode(root, x);
				
				if (node == NULL)	
				{
					cout << "The data that you want to search isn't existed!\n";
				}
				else
				{
					if (node == root)
					{
						cout << node->data << " exist and it's root!\n";
					}
					else
					{
						cout << node->data << " exist!\n"
							<< "Parent: " << node->parent->data << "\n";
					}
				}
					
				break;
			}
			case 5: {
				cout << "BINARY DATA:\n\n";
         		cout << "InOrder: "; inOrder(root); cout << "\n";
            	cout << "PreOrder: "; preOrder(root); cout << "\n";
            	cout << "PostOrder: "; postOrder(root); cout << "\n";
            	cout << "LevelOrder:\n"; levelOrder(root); cout << "\n";
				break;
			}
			case 6: {
				cout << "BYE!\n";
				break;
			}
			default: {
				cout << "Wrong input!\n";
				break;
			}
		}
		
		system("PAUSE");
		
	} while(pil != 6);
	
	return 0;
}

Node *searchNode(Node *node, int x)
{
	if (node == NULL || node->data == x)
	{
		return node;
	}
	else if (x < node->data)
	{
		return searchNode(node->left, x);
	}
	else if (x > node->data)
	{
		return searchNode(node->right, x);
	}
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
		Node *new_node = new Node(x);
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
	if (x < node->data)
	{
		node->left =  insertTree(node->left, x, node);
	}
	else if (x > node->data)
	{
		node->right = insertTree(node->right, x, node);
	}
	else
	{
		cout << "Data cannot be duplicated!\n";
		return node;
	}
	
	return node;
}

Node *deleteTreeByMerging(Node *node, int x)
{
	if (node == NULL)
	{
		cout << "Data doesn't exist!\n";
		return node;
	}
	else if (x < node->data)
	{
		node->left = deleteTreeByMerging(node->left, x);
	}
	else if (x > node->data)
	{
		node->right = deleteTreeByMerging(node->right, x);
	}
	else 
	{
		if (node->left == NULL && node->right == NULL)
		{
			node = NULL;
			free(node);
		}
		else if (node->left != NULL && node->right == NULL)
		{
			Node *temp = node->left;
			free(node);
			return temp;
		}
		else if (node->left == NULL && node->right != NULL)
		{
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->left != NULL && node->right != NULL)
		{
			Node *temp = findPredeccessor(node->left);
			temp->right = node->right;
			temp = node;
			node = node->left;
			free(temp);
		}
	}
	
	return node;
}

Node *deleteTreeByCopying(Node *node, int x)
{
	if (node == NULL)
	{
		cout << "Data doesn't exist!\n";
		return node;
	}
	else if (x < node->data)
	{
		node->left = deleteTreeByCopying(node->left, x);
	}
	else if (x > node->data)
	{
		node->right = deleteTreeByCopying(node->right, x);
	}
	else 
	{
		if (node->left == NULL && node->right == NULL)
		{
			node = NULL;
			free(node);
		}
		else if (node->left != NULL && node->right == NULL)
		{
			Node *temp = node->left;
			free(node);
			return temp;
		}
		else if (node->left == NULL && node->right != NULL)
		{
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->left != NULL && node->right != NULL)
		{
			Node *temp = findPredeccessor(node->left);
			node->data = temp->data;
			node->left = deleteTreeByCopying(node->left, temp->data);
		}
	}
	
	return node;
}

void inOrder(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

void preOrder(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void postOrder(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

int heightTree(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = heightTree(node->left);
		int rheight = heightTree(node->right);
		
		if (lheight > rheight)
		{
			return (lheight + 1);	
		} 
		else
		{
			return (rheight + 1);
		}
	}
}

void printGivenLevel(Node *node, int level)
{
	if (node == NULL)
	{
		cout << "N "; 
		return;
	}
	if (level == 1)
	{
		cout << node->data << " ";
	}
	else if (level > 1)
	{
		printGivenLevel(node->left, level-1);
		printGivenLevel(node->right, level-1);
	}
}

void levelOrder(Node *node)
{
	int h = heightTree(node);
	
	for(int i=1; i<=h; i++)
	{
		cout << "Level-" << i << ": ";
		printGivenLevel(node, i);
		cout << "\n";
	}
}

