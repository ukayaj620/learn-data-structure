#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	Node *next;
};

struct Graph 
{
	int vertices;
	Node **list;
};

Graph *initGraph(int vertices)
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->list = (Node**)malloc(vertices * sizeof(Node*));
	for (int i=0; i<vertices; i++)
	{
		graph->list[i] = (Node*)malloc(sizeof(Node));
		graph->list[i] = NULL;
	}
	
	return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = dest;
	new_node->next = NULL;
	if (graph->list[src] == NULL)
	{
		graph->list[src] = new_node;
	}
	else
	{
		Node *temp = graph->list[src];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	
	// comment these lines until before 
	// curly braces if it is a digraph (directed graph)
	
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = src;
	new_node->next = NULL;
	if (graph->list[dest] == NULL)
	{
		graph->list[dest] = new_node;
	}
	else
	{
		Node *temp = graph->list[dest];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void printGraph(Graph *graph)
{
	for (int i=0; i<graph->vertices; i++)
	{
		Node *temp = graph->list[i];
		printf("Adjacency list of vertex %d\nhead", i);
		while (temp != NULL)
		{
			printf("-> %d", temp->data);
			temp = temp->next;
		}
		printf("\n\n");
	}
}

int main ()
{
	Graph* graph = initGraph(5);
	
	addEdge(graph,0,1);
	addEdge(graph,0,4);
	addEdge(graph,1,2);
	addEdge(graph,1,3);
	addEdge(graph,1,4);
	addEdge(graph,2,3);
	addEdge(graph,3,4);
	
	printGraph(graph);
	return 0;
}
