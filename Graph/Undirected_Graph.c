//Undirected Graph
#include <stdio.h>

#define MAX 10

int adjmatrix[MAX][MAX];

void addedge(int u, int v)
{
    adjmatrix[u][v]=1;
    adjmatrix[v][u]=1;//Undirected Graph
}

void printgraph(int vertices)
{
    printf("Adjacency Matrix\n");
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("%d ",adjmatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices,edges;
    int u,v;
    
    printf("Enter number of vertices:");
    scanf("%d",&vertices);
    
    printf("Enter number of Edges :");
    scanf("%d",&edges);
    
    for(int i=0;i<edges;i++)
    {
        printf("Enter edge (u,v): ");
        scanf("%d %d",&u,&v);
        addedge(u,v);
    }
    
    printgraph(vertices);

    return 0;
}
