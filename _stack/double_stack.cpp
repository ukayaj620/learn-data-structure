#include <iostream>
#define MAX 9999

using namespace std;

void pushStackA(int);
void pushStackB(int);

void popStackA();
void popStackB();

void printStackA();
void printStackB();

int stack[MAX];

int topStackA = -1;
int topStackB = MAX;

int main ()
{
	int pil;
	do
	{
		system("CLS");
		cout << "DOUBLE STACK\n"
			<< "1. PUSH STACK A\n2. PUSH STACK B\n"
			<< "3. POP STACK A\n4. POP STACK B\n"
			<< "5. PRINT STACK\n6. EXIT\n"
			<< "Your choice: "; 
		cin >> pil;
		
		switch(pil)
		{
			case 1: {
				int num;
				cout << "Input a number: "; cin >> num;
				pushStackA(num);
				break;
			}
			case 2: {
				int num;
				cout << "Input a number: "; cin >> num;
				pushStackB(num);
				break;
			}
			case 3: {
				popStackA();
				break;
			}
			case 4: {
				popStackB();
				break;
			}
			case 5: {
				printStackA();
				printStackB();
				break;
			}
			case 6: {
				cout << "BYE!\n";
				break;
			}
			default: {
				cout << "Wrong input!\n";
				break;
			}
		}
		
		system("PAUSE");
		
	} while(pil != 6);
	
	return 0;
}

void pushStackA(int x)
{
	if (topStackA == topStackB-1)
	{
		cout << "STACK A OVERFLOW!\n";
	}
	else
	{
		stack[++topStackA] = x;
		cout << x << " has been pushed into stack!\n";
	}
}

void pushStackB(int x)
{
	if (topStackB == topStackA+1)
	{
		cout << "STACK B OVERFLOW!\n";
	}
	else
	{
		stack[--topStackB] = x; 
		cout << x << " has been pushed into stack!\n";
	}
}

void popStackA()
{
	if (topStackA == -1)
	{
		cout << "STACK A UNDERFLOW!\n";
	}
	else
	{
		cout << stack[topStackA--] << " has been poped out from stack A!\n";	
	}
}

void popStackB()
{
	if (topStackB == MAX)
	{
		cout << "STACK B UNDERFLOW!\n";
	}
	else
	{
		cout << stack[topStackB++] << " has been poped out from stack A!\n";	
	}
}

void printStackA()
{
	cout << "STACK A POOL:\n";
	for(int i=topStackA; i>=0; i--)
	{
		cout << stack[i] << "\n";
	}
	cout << "\n";
}

void printStackB()
{
	cout << "STACK B POOL:\n";
	for(int i=topStackB; i<MAX; i++)
	{
		cout << stack[i] << "\n";
	}
	cout << "\n";
}

