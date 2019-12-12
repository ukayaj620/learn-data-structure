#include <iostream>

using namespace std;

struct Node 
{
	int data;
	Node *prev;
	Node *next;	
};

Node *head = NULL, *tail = NULL;

void insertHead(int);
void insertTail(int);
void insertBefore(int, int);
void insertAfter(int, int);
void insertMid(int, int)

int main()
{
	
	return 0;
}

void insertHead(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->prev = NULL;
	new_node->data = x;
	
	if (head == NULL)
	{
		new_node->next = NULL;
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	
}

void insertTail(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = x;
	
	if (head == NULL)
	{
		new_node->next = NULL;
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
}
