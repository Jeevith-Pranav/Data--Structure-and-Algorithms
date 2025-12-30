//Circular Linked List
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
    newnode -> data =value;
    
    if(head == NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        
        while(temp -> next != head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    
}

void display()
{
    if(head == NULL)
    {
        printf("The List is empty");
        return ;
    }
    struct node *temp=head;
    
    do
        {
        printf("%d ",temp-> data);
        temp=temp->next;
        
        }
    while(temp != head);
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
