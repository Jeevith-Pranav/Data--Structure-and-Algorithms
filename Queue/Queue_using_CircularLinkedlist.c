//Queue Using Circular linked list
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    
    if(front == NULL)
    {
        front = rear = newnode;
        newnode->next=front;
    }
    else
    {
        rear->next=newnode;
        newnode->next=front;
        rear=newnode;
    }
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct node *temp=front;
    printf("Queue Elements:");
    
    do{
        printf("%d ",temp->data);
        temp=temp->next;
        
    }while(temp != front);
}

int main()
{
    
    int n,data;
    printf("Enter your elements count:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        enqueue(data);
    }
    display();
    return 0;
}
