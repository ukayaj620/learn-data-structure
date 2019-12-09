#include <stdio.h>
#include <stdlib.h>
#define MAX 9999

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int);
void dequeue();
void printQueue();

int main ()
{
	int pil;
	do
	{
		system("CLS");
		printf("SINGLE QUEUE\n1. ENQUEUE\n2. DEQUEUE\n3. PRINT\n4. EXIT\nYour choice: "); 
		scanf("%d",&pil);
		
		switch(pil)
		{
			case 1: {
				int num;
				printf("Input a number: "); 
				scanf("%d",&num);
				enqueue(num);
				break;
			}
			case 2: {
				dequeue();
				break;
			}
			case 3: {
				printQueue();
				break;
			}
			case 4 : {
				printf("BYE!\n");
				break;
			}
			default: {
				printf("Wrong input!\n");
				break;
			}
		}
		
		system("PAUSE");
		
	}while (pil != 4);
	return 0;
}

void enqueue(int x)
{
	if (rear == MAX-1)
	{
		printf("QUEUE OVERFLOW!\n");
	}
	else
	{
		queue[++rear] = x;
		printf("%d has been enqueue into queue!\n",queue[rear]);
	}
}

void dequeue()
{
	if (front == rear + 1)
	{
		printf("QUEUE UNDERFLOW!\n");
	}
	else
	{
		printf("%d has been dequeue out from queue!\n",queue[front++]);
		if (front > rear || front == MAX)
		{
			front = 0;
			rear = -1;
		}
	}
}

void printQueue()
{
	printf("\nQUEUE LINE:\n");
	for (int i=front; i<=rear; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}
