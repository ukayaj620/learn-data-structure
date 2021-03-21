#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int priority;
	Node *next	
};

Node *head = NULL, *tail = NULL;

void enqueue(int, int);
void dequeue();
void printQueue();

int main ()
{
	int pil;
	do 
	{
		system("CLS");
		printf("PRIORITY QUEUE\n1. ENQUEUE\n2. DEQUEUE\n3. PRINT\n4. EXIT\nYour choice: ");
		scanf("%d", &pil);
		
		switch(pil)
		{
			
		}
	} while (pil != 3);
	
	return 0;
}

void enqueue(int x, int p)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	new_node->priority = p;
	if (head == NULL || p < head->priority)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		
	}
}

void dequeue()
{
	
}

void printQueue()
{
	
}
