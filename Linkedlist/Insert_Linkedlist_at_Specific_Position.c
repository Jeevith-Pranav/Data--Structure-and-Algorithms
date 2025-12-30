//Insert Linked list at specific position
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
    newnode -> next =NULL;
    if(head == NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp -> next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
}

void insert(int pos,int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode -> data =value;
    
    struct node *temp=head;
    
    if(pos == 1)
    {
        newnode->next=temp;
        head=newnode;
    }
    
    else
    {
        for(int i=1;i<pos-1 && temp != NULL ; i++)
        {
            temp = temp-> next;
        }
        
        newnode->next=temp->next;
        temp->next=newnode;
    }
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
    int a;
    printf("Enter your node size:");
    scanf("%d",&a);
    
    int value;
    for(int i=0;i<a;i++)
    {
        scanf("%d",&value);
        
        if(a>0)
        {
            append(value);
        }
    }
    printf("The Values are:");
    display();
    
    int pos;
    printf("\nEnter your position and element:");
    scanf("%d %d",&pos,&value);
    insert(pos,value);
    display();
 
}
