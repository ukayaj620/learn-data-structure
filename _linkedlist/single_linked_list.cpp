#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node *next;
};

Node *head = NULL, *tail = NULL;

void insertHead(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	new_node->next = head;
	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		head = new_node; 
	}
}

void insertTail(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
}

void insertBefore(int before, int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	Node *ptr = head;
	Node *preptr;
	
	if (head->data == before)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		while (ptr->data != before)
		{
			preptr = ptr;
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
				return ;
			}
		}
		new_node->next = ptr;
		preptr->next = new_node;
	}
}

void insertAfter(int after, int x)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	Node* ptr = head;
	
	if (tail->data == after)
	{
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		while (ptr->data != after)
		{
			ptr = ptr->next;
			if (ptr->next == NULL)
			{
				printf("No data found!\n");
				return;
			}
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

void printList()
{
	Node* ptr = head;
	while (ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	// code to try
	insertHead(10);
	printList();
	
	insertTail(20);
	printList();
	
	insertHead(30);
	printList();
	
	insertBefore(30,100);
	printList();
	
	insertHead(200);
	printList();
	
	insertTail(80);
	printList();
	
	insertAfter(80,70);
	printList();
	return 0;
}
