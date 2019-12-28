#include <stdio.h>
#include <stdlib.h>
#define MAX 9999

void enqueue_left(int);
void enqueue_right(int);
void dequeue_left();
void dequeue_right();
void printQueue();

int queue[MAX];
int left = -1;
int right = -1;

int main ()
{
	int pil;
	do
	{
		system("CLS");
		printf("DOUBLE QUEUE\n1. Input Restricted Queue\n2. Output Restricted Queue\n3. Exit\nYour choice: ");
		scanf("%d", &pil);
		
		switch(pil)
		{
			case 1: {
				int pil2;
				do
				{
					system("CLS");
					printf("INPUT RESTRICTED QUEUE\n1. Enqueue Right\n2. Dequeue Left\n3. Dequeue Right\n4. Print\n5. Exit\nYour choice: ");
					scanf("%d", &pil2);
					
					switch(pil2) 
					{
						case 1: {
							int num;
							printf("Input a number: ");
							scanf("%d", &num);
							enqueue_right(num);
							break;
						}	
						case 2: {
							dequeue_left();
							break;
						}
						case 3: {
							dequeue_right();
							break;
						}
						case 4: {
							printQueue();
							break;
						}
						case 5: {
							printf("Back to menu!\n");
							break;
						}
						default: {
							printf("Wrong input!\n");
							break;
						}
					}
					
					system("PAUSE");
					
				}while (pil2 != 5);
				
				break;
			}
			case 2: {
				int pil2;
				do
				{
					system("CLS");
					printf("OUTPUT RESTRICTED QUEUE\n1. Enqueue Right\n2. Enqueue Left\n3. Dequeue Left\n4. Print\n5. Exit\nYour choice: ");
					scanf("%d", &pil2);
					
					switch(pil2) 
					{
						case 1: {
							int num;
							printf("Input a number: ");
							scanf("%d", &num);
							enqueue_right(num);
							break;
						}	
						case 2: {
							int num;
							printf("Input a number: ");
							scanf("%d", &num);
							enqueue_left(num);
							break;
						}
						case 3: {
							dequeue_left();
							break;
						}
						case 4: {
							printQueue();
							break;
						}
						case 5: {
							printf("Back to menu!\n");
							break;
						}
						default: {
							printf("Wrong input!\n");
							break;
						}
					}
					
					system("PAUSE");
					
				}while (pil2 != 5);
				
				break;
			}
			case 3: {
				printf("BYE!\n");
				break;
			}
			default: {
				printf("Wrong input!\n");
				break;
			}
		}
		
		system("PAUSE");
		
	}while (pil != 3);
	
	return 0;
}

void enqueue_left(int x)
{
	if ((left == 0 && right == MAX-1) || left == right + 1)
	{
		printf("QUEUE OVERFLOW!\n");
		return;
	}
	else if (left == -1)
	{
		left = 0;
		right = 0;
	}
	else
	{
		if (left == 0)
		{
			left = MAX-1;
		}
		else
		{
			left--;
		}
	}
	queue[left] = x;
	printf("%d has been enqueue left into queue!\n",x);
}

void enqueue_right(int x)
{
	if ((left == 0 && right == MAX-1) || left == right + 1)
	{
		printf("OVERFLOW!\n");
		return;
	}
	else if (left == -1)
	{
	   left = 0;
	   right = 0;
	}
	else
	{
		if (right == MAX-1)
		{
			right = 0;
		}
		else
		{
			right++;
		}
	}
   queue[right] = x;
   printf("%d has been enqueue right into queue!\n",x);
}

void dequeue_left()
{
	if (left == -1)
	{
		printf("UNDERFLOW!\n");
	}
	printf("Out Data: %d\n",queue[left]);
	if (left == right)
	{
		left = -1;
		right = -1;
	}
	else
	{
		if (left == MAX-1)
		{
	  		left = 0;
		}
		else
		{
			left++;
		}
	}
}

void dequeue_right()
{
	if (left == -1)
	{
		printf("UNDERFLOW!\n");
	}
	printf("Out Data: %d\n",queue[right]);
	if (left == right)
	{
		left = -1;
		right = -1;
	}
	else
	{
		if (right == 0)
		{
			right = MAX-1;
		}
		else
		{
			right--;
		}
	}
}

void printQueue()
{
	printf("\nQUEUE LINE:\n");
	int front = left;
	int rear = right;
	if (front != -1)
	{
		if (front <= rear)
		{
			for (int i=front; i<=rear; i++)
			{
				printf("[%d]: %d\n",i,queue[i]);
			}
		}
		else
		{
			for (int i=front; i<MAX; i++)
			{
				printf("[%d]: %d\n",i,queue[i]);
			}
			for (int i=0; i<=rear; i++)
			{
				printf("[%d]: %d\n",i,queue[i]);
			}
		}
	}
}
