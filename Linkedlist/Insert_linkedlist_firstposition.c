//Insert linked list at First Position
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void append(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode -> data=value;
    newnode -> next=head;
    head=newnode;
}

void display()
{
    struct node *temp=head;
    
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int n,value;
    printf("Enter number of node:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        
        if(value>0)
        {
            append(value);
        }
    }
    display();

    return 0;
}
