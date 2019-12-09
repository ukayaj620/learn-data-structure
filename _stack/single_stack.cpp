#include <iostream>
#define MAX 9999

using namespace std;

void push(int);
void pop();
void printStack();

int stack[MAX];
int top = -1;

int main()
{
	int pil;
	do
	{
		system("CLS");
		cout << "SINGLE STACK\n"
			<< "1. PUSH\n2. POP\n3. PRINT\n4. EXIT\n"
			<< "Your choice: "; 
		cin >> pil;
		
		switch(pil)
		{
			case 1: {
				int num;
				cout << "Input a number: "; cin >> num;
				push(num);
				break;
			}
			case 2: {
				pop();
				break;
			}
			case 3: {
				printStack();
				break;
			}
			case 4: {
				cout << "BYE!\n";
				break;
			}
			default: {
				cout << "Wrong input!\n";
				break;
			}
		}
		
		system("PAUSE");
		
	}while (pil != 4);
	return 0;
}

void push(int num)
{
	if (top == MAX) 
	{
		cout << "\nSTACK OVERFLOW!\n";
		return;
	} 
	else
	{
		stack[++top] = num;
		cout << num << " has been pushed into stack!\n";
	}
}

void pop()
{
	if (top == -1)
	{
		cout << "STACK UNDERFLOW!\n";
		return;
	}
	else
	{
		cout << stack[top--] << " has been poped out from stack!\n";
	}
}

void printStack()
{
	int n = top + 1;
	cout << "\nSTACK POOL:\n";
	while(n--)
	{
		cout << stack[n] << "\n";
	}
}
