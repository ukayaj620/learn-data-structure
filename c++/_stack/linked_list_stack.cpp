#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *next;	
};

Node *top = NULL;

void push(int);
void pop();
void displayStack();

int main()
{
	push(20);
	displayStack();
	
	push(30);
	displayStack();
	
	push(40);
	displayStack();
	
	pop();
	displayStack();

	return 0;
}

void push(int x)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = x;
	
	if (top == NULL)
	{
		new_node->next = NULL;
		top = new_node;
	}
	else
	{
		new_node->next = top;
		top = new_node;
	}
}

void pop()
{
	if (top == NULL)
	{
		printf("STACK UNDERFLOW!\n");
	}
	else
	{
		Node *temp = top;
		top = top->next;
		printf("Out Data: %d\n", temp->data);
		free(temp);
	}
}

void displayStack()
{
	if (top == NULL)
	{
		printf("Stack is empty!\n");
	}
	else
	{
		Node *ptr = top;
		printf("STACK POOL:\n");
		while (ptr != NULL)
		{
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
	}
}
