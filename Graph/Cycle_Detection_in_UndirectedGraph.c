/*
Union–Find for Cycle Detection:
Union–Find is a technique used to detect cycles in an undirected graph by checking whether two vertices 
of an edge belong to the same set before joining them.
*/
#include <stdio.h>

#define V 5   
#define E 4   

int find(int parent[], int i) 
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) 
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int isCycle(int edges[E][2]) 
{
    int parent[V];

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < E; i++) 
    {
        int x = find(parent, edges[i][0]);
        int y = find(parent, edges[i][1]);

        if (x == y)
        {
            return 1; 
        }

        unionSet(parent, x, y);
    }
    return 0;
}

int main() 
{
    int edges[E][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 2}   // this creates a cycle
    };

    if (isCycle(edges))
        printf("Cycle detected\n");
        
    else
        printf("No cycle\n");

    return 0;
}
