//Priority Queue
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front=NULL;

void enqueue(int data,int priority)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->priority=priority;
    newnode->next=NULL;
    
    
    if(front == NULL || priority < front -> priority)
    {
        newnode->next=front;
        front=newnode;
    }
    else
    {
        struct node *temp=front;
        
        while(temp -> next != NULL && temp->priority <= priority)
        {
            temp= temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}


void display()
{
    struct node *temp=front;
    if(temp == NULL)
    {
        printf("Queue is empty");
        return;
    }
   
    printf("The Elements are:");
    while(temp != NULL)
    {
        printf("(%d, p=%d) ",temp->data,temp->priority);
        temp=temp->next;
    }
}

int main()
{
    int n;
    printf("Enter your elements Size:");
    scanf("%d",&n);
    
    int data,priority;
    
    for(int i=0;i<n;i++)
    {
        printf("Enter your data %d:",i+1);
        scanf("%d",&data);
        printf("Enter your priority:");
        scanf("%d",&priority);
        enqueue(data,priority);
    }
    display();

    return 0;
}
