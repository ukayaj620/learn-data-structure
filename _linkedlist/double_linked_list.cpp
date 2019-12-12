#include <stdio.h>
#include <stdlib.h>

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
void insertMid(int, int);

void deleteHead();
void deleteTail();
void deleteBefore(int);
void deleteAfter(int);
void deleteMid(int);

void printList();

int main()
{
	insertHead(100);
	printList();
	
	insertHead(600);
	printList();
	
	insertTail(200);
	printList();
	
	insertTail(800);
	printList();
	
	insertBefore(600,300);
	printList();
	
	insertAfter(800,400);
	printList();
	
	insertBefore(200,111);
	printList();
	
	insertAfter(100,222);
	printList();
	
	insertHead(333);
	printList();
	
	insertTail(444);
	printList();
	
	insertMid(1,555);
	printList();
	
	insertMid(2,666);
	printList();
	
	insertMid(12,777);
	printList();
	
	insertMid(14,888);
	printList();
	
	insertMid(20,999);
	printList();
	
	insertBefore(555,1);
	printList();
	
	insertHead(2);
	printList();
	
	deleteHead();
	printList();
	
	deleteTail();
	printList();
	
	deleteBefore(555);
	printList();
	
	deleteBefore(200);
	printList();
	
	deleteAfter(555);
	printList();
	
	deleteAfter(100);
	printList();
	
	deleteAfter(400);
	printList();
	
	deleteAfter(400);
	printList();
	
	deleteMid(2);
	printList();
	
	deleteMid(1);
	printList();
	
	deleteMid(6);
	printList();
	
	insertMid(3,888);
	printList();
	
	insertMid(6,4141);
	printList();
	
	insertMid(8,8080);
	printList();
	
	deleteMid(8);
	printList();
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

void insertBefore(int before, int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	Node *ptr = head;
	
	if (head->data == before)
	{
		new_node->prev = NULL;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		while (ptr->data != before)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
			}
		}
		new_node->prev = ptr->prev;
		ptr->prev->next = new_node;
		new_node->next = ptr;
		ptr->prev = new_node;
		
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
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
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
		new_node->next = ptr->next;
		ptr->next->prev = new_node;
		new_node->prev = ptr;
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
		new_node->prev = NULL;
		new_node->next = head;
		head->prev = new_node;
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
			new_node->prev  = tail;
			tail->next = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = ptr->next;
			ptr->next->prev = new_node;
			new_node->prev = ptr;
			ptr->next = new_node;
		}
	}
}

void deleteHead()
{
	Node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}

void deleteTail()
{
	Node* temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
}

void deleteBefore(int before)
{
	Node* ptr = head;
	
	if (head->data == before)
	{
		printf("No data can be deleted!\n");
		return;
	}
	else if (head->next->data == before)
	{
		head = head->next;
		head->prev = NULL;
		free(ptr);
	}
	else
	{
		while(ptr->data != before)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
				return;
			}
		}
		Node* temp = ptr->prev; 
		temp->prev->next = ptr;
		ptr->prev = temp->prev;
		free(temp);
	}
}

void deleteAfter(int after)
{
	Node* ptr = head;
	
	if (tail->data == after)
	{
		printf("No data can be deleted!\n");
	}
	else if (tail->prev->data == after)
	{
		Node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
	else
	{
		while(ptr->data != after)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printf("No data found!\n");
				return;
			}
		}
		Node* temp = ptr->next;
		ptr->next = temp->next;
		temp->next->prev = ptr;
		free(temp);
	}
}

void deleteMid(int pos)
{
	Node* ptr = head;
	
	if (pos == 1)
	{
		head = head->next;
		head->prev = NULL;
		free(ptr);
	}
	else
	{
		for(int i=1; i<pos; i++)
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
			tail = tail->prev;
			tail->next = NULL;
			free(ptr);
		}
		else
		{
			Node* preptr = ptr->prev;
			preptr->next = ptr->next;
			ptr->next->prev = preptr;
			free(ptr);
		}
	}
}

void printList()
{
	Node* ptr1 = head;
	Node* ptr2 = tail;
	
	printf("From head: ");
	while (ptr1 != NULL)
	{
		printf("%d ",ptr1->data);
		ptr1 = ptr1->next;
	}
	printf("\nFrom tail: ");
	while (ptr2 != NULL)
	{
		printf("%d ",ptr2->data);
		ptr2 = ptr2->prev;
	}
	printf("\n\n");
}
