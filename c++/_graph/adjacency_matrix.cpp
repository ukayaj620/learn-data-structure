#include <stdio.h>
#include <stdlib.h>

void initializeMatrix(int **, int);
void addEdge(int **, int, int);
void printMatrix(int **, int);

int main ()
{
	int n;
	printf("How much vertex?: ");
	scanf("%d", &n);
	
	int **arr = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++)
	{
		arr[i] = (int*)malloc(n*sizeof(int));
	}
	
	initializeMatrix(arr, n);
	
	printMatrix(arr, n);
	
	addEdge(arr,0,1);
	addEdge(arr,0,4);
	addEdge(arr,1,2);
	addEdge(arr,1,3);
	addEdge(arr,1,4);
	addEdge(arr,2,3);
	addEdge(arr,3,4);
	
	printMatrix(arr,n);
	
	return 0;
}

void initializeMatrix(int **arr, int n)
{
	for(int i=0; i<n; i++) 
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}	
	}
}

void addEdge(int **arr, int src, int dest)
{
	arr[src][dest]++;
	arr[dest][src]++; // for digraph
}

void printMatrix(int **arr, int n)
{
	printf("ADJACENCY MATRIX:\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("|%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
