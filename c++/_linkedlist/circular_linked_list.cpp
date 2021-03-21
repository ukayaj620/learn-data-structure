#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *next;	
};

Node *head = NULL, *tail = NULL;

void insertHead(int);
void insertTail(int);
void insertBefore(int, int);
void insertAfter(int, int);

void deleteHead();
void deleteTail();
void deleteBefore(int);
void deleteAfter(int);

int searchList(Node*, int, int);

void printList();

int main()
{
	insertHead(45);
	printList();
	
	insertHead(78);
	printList();
	
	insertBefore(45,88);
	printList();
	
	insertAfter(45,71);
	printList();
	
	deleteHead();
	printList();
	
	deleteHead();
	printList();
	
	deleteTail();
	printList();
	
	insertTail(23);
	printList();
	
	deleteBefore(45);
	printList();
	
	insertHead(123);
	printList();
	
	int index = searchList(head, 123, 1); 
	(index != -1) ? printf("Exist at index %d!\n", index) : printf("Not Exist!\n");
	
	insertTail(56);
	printList();
	
	deleteAfter(56);
	printList();
	
	deleteAfter(45);
	printList();
		
	if (tail->next == head)
	{
		printf("Horray\n");
	}
	
	return 0;
}

void insertHead(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	if (head == NULL)
	{
		new_node->next = new_node;
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->next = head;
		tail->next = new_node;
		head = new_node;
	}
}

void insertTail(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	if (head == NULL)
	{
		new_node->next = new_node;
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->next = head;
		tail->next = new_node;
		tail = new_node;
	}
}

void insertBefore(int before, int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	if (head != NULL)
	{
		if (head->data == before)
		{
			new_node->next = head;
			tail->next = new_node;
			head = new_node;
		}
		else
		{
			Node *ptr = head;
			Node *preptr;
			
			do
			{
				preptr = ptr;
				ptr = ptr->next;
				if (ptr == head)
				{
					printf("No data found!\n");
					return;
				}
			} while(ptr->data != before);
			
			preptr->next = new_node;
			new_node->next = ptr;
		}
	}
}

void insertAfter(int after, int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	if (head != NULL)
	{
		if (tail->data == after)
		{
			new_node->next = head;
			tail->next = new_node;
			tail = new_node;
		}
		else
		{
			Node *ptr = tail;
			
			do
			{
				ptr = ptr->next;
				if (ptr == tail)
				{
					printf("No data found!\n");
					return;
				}
			} while(ptr->data != after);
			
			Node *temp = ptr->next;
			new_node->next = temp;
			ptr->next = new_node;
		}
	}
}

void deleteHead()
{
	if (head == tail)
	{
		free(head);
		head = NULL;
		tail = NULL;
	}
	else
	{
		Node *temp = head;
		head = head->next;
		tail->next = head;
		free(temp);
	}
}

void deleteTail()
{
	if (head == tail)
	{
		free(head);
		head = NULL;
		tail = NULL;
	}
	else
	{
		Node *ptr = head;
		while(ptr->next != tail)
		{
			ptr = ptr->next;
		}
		Node *temp = tail;
		ptr->next = head;
		tail = ptr;
		free(temp);
	}
}

void deleteBefore(int before)
{
	if (head != NULL)
	{
		if (head->next->data = before)
		{
			Node *temp = head;
			head = head->next;
			tail->next = head;
			free(temp);
		}
		else
		{
			Node *ptr = head;
			Node *preptr;
			do
			{
				preptr = ptr;
				ptr = ptr->next;
				if (ptr == head)
				{
					printf("No data found!\n");
					return;
				}
			} while(ptr->next->data != before);
			
			if (ptr->next == head)
			{
				preptr->next = head;
				tail = preptr;
				free(ptr); 
			}
			else
			{
				preptr->next = ptr->next;
				free(ptr);
			}
		}
	}
}

void deleteAfter(int after)
{
	if (head != NULL)
	{
		if (tail->data == after)
		{
			Node *temp = head;
			head = head->next;
			tail->next = head;
			free(temp);
		}
		else
		{
			Node* ptr = tail;
			do
			{
				ptr = ptr->next;
				if (ptr == tail)
				{
					printf("No data found!\n");
					return;
				}
			}while (ptr->data != after);
			
			if (ptr->next == tail)
			{
				Node *temp = tail;
				ptr->next = head;
				tail = ptr;
				free(temp);
			}
			else
			{
				Node *temp = ptr->next;
				ptr->next = temp->next;
				free(temp);
			}
		}
	}
}

int searchList(Node* ptr, int find, int index)
{
	if (ptr->data == find)
	{
		return index;
	}
	else if (ptr == head && index != 1)
	{
		return -1;
	}
	else
	{
		return searchList(ptr->next, find, index + 1);
	}
}

void printList()
{
	Node *ptr = head;
	if (head != NULL) 
	{
		do 
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		} while(ptr != head);
	}
	printf("\n");
}


