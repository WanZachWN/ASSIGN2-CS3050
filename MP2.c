/*
 *	Name: Wan Fatimah Wan Nawawi
 * 	ID: 14300239
 * 	PawPrint: ww838
 *
 * 	Name: Sean Ficken
 * 	ID: 14252441
 * 	PawPrint: swfzq8
 *
 */

 /* Marking all vertices as not visited and fill the link list as a stack
  * display all vertices in stack order by poping
  * if a node is not visited, print the strongly component and mark it as visit
  *
  */



#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    int n;
    struct Node *head;
};

struct LinkedList* push(struct LinkedList *list, int data)
{
	if (list == NULL)
	{
		list = malloc(sizeof(struct LinkedList));
		list->n = 0;
		list->head = malloc(sizeof(struct Node));
		list->head->data = data;
		list->head->next = NULL;
		return list;
	}

    struct Node *current = list->head;
    while (current->next != NULL)
    {
    	if (current->data == data)
    	{
    		return list;
		}

        current = current->next;
    }

    current->next = malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;
    list->n = list->n + 1;

    return list;
}

int get(struct LinkedList *list, int n)
{
	int i;
	struct Node *current = list->head;

	for(i = 0; i < n; i++)
	{
		if (current != NULL)
		{
			current = current->next;
		}
		else
		{
			return -1;
		}
	}

	return current->data;
}

struct Node* find(struct LinkedList *list, int key)
{
	printf("k%d\n", key);
	struct Node *current = list->head;
	while (current != NULL)
	{
		if (current->data == key)
		{
			return current;
		}
		current = current->next;
	}

	return current;
}

void eSquared(struct LinkedList **adj, int V, char* outputfile)
{
	char* output = outputfile;
	int v;

	FILE *outlist;

	outlist = fopen(output,"w");
	 if(outlist == NULL){
		printf("The file does not exist\n");
		return;
	}
    for (v = 1; v < V; ++v)
	{
		int i;
		struct Node *current;
        struct LinkedList *set = NULL;

        printf("%d:", v);
        for (i = adj[v]->n - 1; i >= 0; --i)
		{
			int j;
            int x = get(adj[v], i);
            for (j = adj[x]->n - 1; j >= 0; --j)
			{

                int y = get(adj[x], j);
                if (y != v)
                {
                	set = push(set, y);
				}
            }
        }

        current = set->head;
        while (current != NULL)
		{
            printf(" %d", current->data);
            fprintf(outlist, "%C", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    char ch;
    char* inputfile = argv[1];
    char* outputfile = argv[2];
    FILE *aFile;
    int V = 0;
    int i;
    struct LinkedList **adj;

    if(argc != 3){
		printf("not enough arguments\n<inputfilename> <outputfilename>\n");
		return(1);
	}

    aFile = fopen(inputfile, "r"); /*read file*/
    if(aFile == NULL){
		printf("The file does not exist\n");
		return(1);
	}
    int temp = 0;
    while(fscanf(aFile,"%d ", &temp) != EOF)
    {
        if (temp > V)
        {
        	V = temp;
		}
    }
    fclose(aFile);

    adj = malloc((V + 1) * sizeof(struct LinkedList));
    for (i = 0; i <= V; i++)
    {
    	adj[i] = NULL;
	}

    aFile = fopen(inputfile, "r"); /*read file*/
    if(aFile != NULL) /*if file is able to open read file, display, and G2*/
    {
        int i = 0;
        int j = 0;

		printf("input:\n");
        while(fscanf(aFile,"%d %d", &i, &j) != EOF)
        {
            printf("%d %d\n",i,j);
            adj[i] = push(adj[i], j);
        }

        printf("output:\n");
        eSquared(adj, V, outputfile);
    }
    else
        printf("Fail to read file. \n");

    fclose(aFile);

    return 0;
}
