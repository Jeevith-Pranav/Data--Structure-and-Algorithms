//Deque Implementation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;


void insert_front(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    
    if(front == NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        newnode->next=front;
        front=newnode;
    }
}

void insert_rear(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    
    if(front == NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void delete_front()
{
    struct node *temp=front;
    front=front->next;
    free(temp);
}

void delete_rear()
{
    struct node *temp=front;
    
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    
    free(rear);
    
    temp->next=NULL;
    rear=temp;
}


void display()
{
    struct node *temp=front;
    
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    printf("Enter your choice:\n");
    printf("1.Insert front\n2.Insert rear\n3.delete front\n4.delete rear\n5.dispalay\n-1.Exit\n");
    while(1)
    {
        int choice;
        scanf("%d",&choice);
        
        if(choice == -1)
        {
            break;
        }
        
        else
        {
            switch(choice)
            {
                case 1:
                {
                    int val;
                    scanf("%d",&val);
                    insert_front(val);
                    break;
                }
                
                case 2:
                {
                    int val;
                    scanf("%d",&val);
                    insert_rear(val);
                    break;
                }
                
                case 3:
                {
                    delete_front();
                    break;
                }
                case 4:
                {
                    delete_rear();
                    break;
                }
                case 5:
                {
                    display();
                    break;
                }
                default:
                {
                    printf("Enter the valid input");
                    break;
                }
            }
        }
    }

    return 0;
}
