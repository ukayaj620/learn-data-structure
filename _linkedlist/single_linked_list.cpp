#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node *next;
};

Node *head = NULL, *tail = NULL;

void insertHead(int);
void insertTail(int);
void insertBefore(int, int);
void insertAfter(int, int);
void insertMid(int, int);

void deleteHead();
void deleteTail();
void deleteBefore(int);
void deleteAfter(int);
void deleteMid(int);

void printList();

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
	
	insertMid(3,1000);
	printList();
	
	deleteAfter(200);
	printList();
	
	deleteBefore(1000);
	printList();
	
	deleteMid(1);
	printList();
	
	deleteMid(5);
	printList();
	return 0;
}

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

void insertMid(int pos, int x)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	Node* ptr = head;
	
	if (pos == 1)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		for (int i=1; i<pos-1; i++)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("Out of Bound!\n");
				return;
			}
		}
		if (ptr == tail)
		{
			new_node->next = NULL;
			tail->next = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = ptr->next;
			ptr->next = new_node;
		}
	}
}

void deleteHead()
{
	if (head != NULL)
	{
		if (head == tail)
		{
			free(head);
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			free(temp);
		}
	}
	else
	{
		printf("Linked-List is empty\n");
	}
}

void deleteTail()
{
	if (head != NULL)
	{
		if (head == tail)
		{
			free(head);
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* ptr = head;
			while (ptr->next != tail)
			{
				ptr = ptr->next;
			}
			free(tail);
			tail = ptr;
			tail->next = NULL;
		}
	}
}

void deleteBefore(int before)
{
	Node* ptr = head;
	Node* preptr;
	
	if (head->data == before)
	{
		printf("No data can be deleted!\n");
		return;
	}
	else if (head->next->data == before)
	{
		head = head->next;
		free(ptr);
	}
	else
	{
		while (ptr->next->data != before)
		{
			preptr = ptr;
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
				return;
			}
		}
		preptr->next = ptr->next;
		free(ptr);
	}
}

void deleteAfter(int after)
{
	Node* ptr = head;
	Node* preptr;
	
	if (tail->data == after)
	{
		printf("No data can be deleted!\n");
		return;
	}
	else
	{
		while (ptr->data != after)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
				return;
			}
		}
		if (ptr->next == tail)
		{
			free(tail);
			tail = ptr;
			tail->next = NULL;
		}
		else
		{
			Node* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
		}
	}
}

void deleteMid(int pos)
{
	Node* ptr = head;
	Node* preptr;
	
	if (pos == 1)
	{
		head = head->next;
		free(ptr);
	}
	else
	{
		for (int i=1; i<pos; i++)
		{
			preptr = ptr;
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("Out of Bound!\n");
				return;
			}
		}
		if (ptr == tail)
		{
			free(ptr);
			tail = preptr;
			tail->next = NULL;
		}
		else
		{
			preptr->next = ptr->next;
			free(ptr);
		}
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
