#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    bool visited;
    struct Node* next();
}Node_t;

void DFS(int v, bool visited)
{
    visited = 1;
    printf("%u ", v);
    for(*point = Node.head; i != Node.tail; point = Node.next())
    {
        if(visited != 1)
        {
            DFS(Node.data, Node.visited);
        }
    }
}

void addEdge(struct Node *node, int v, int u)
{
    if (node == NULL)
	{
		node = malloc(sizeof(struct Node));
		node->n = 0;
		node->head = malloc(sizeof(struct Node));
		node->head->data = data;
		node->head->next = NULL;
		return node;
	}

    struct Node *current = node->head;
    while (current->next != NULL)
    {
    	if (current->data == data)
    	{
    		return node;
		}

        current = current->next;
    }

    current->next = malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;
    node->n = node->n + 1;

    return node;
}

void SCCs()
{
    Node_t* current = head;
    for(int i = 0; i < V; i++)
    {
        Node.visited = 0;
        current = current->next();
    }
    while()
    {
        if(Node.visited == 0)
        {
            DFS(Node.data, Node.visited)
        }
    }
}

int main()
{
    Node g;
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    SCCs();

    return 0;
}
