//Deletion of linked list at first position , Last position and specific position
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
    newnode->data=value;
    newnode->next=NULL;
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


void delete_at_first()
{
    if(head == NULL)
    {
        printf("List is Empty ");
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
}


void delete_at_last()
{
    struct node *temp=head;
    struct node *prev=NULL;
    
    while(temp-> next != NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    
    prev->next=NULL;
    free(temp);
    
}


void delete_at_pos(int pos)
{
    struct node *temp=head;
    if(pos == 1)
    {
       head=temp->next;
       free(temp);
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        
        struct node *del;
        
        del=temp->next;
        temp->next=del->next;
        free(del);
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
    int n,value;
    printf("Enter number of nodes to insert:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        append(value);
    }
    
    printf("The arrays are :");
    display();
    
    
    printf("\nThe array After Deleting first element:");
    delete_at_first();
    display();
    
    printf("\nThe array After Deleting last Element:");
    delete_at_last();
    display();
    
    int pos;
    printf("\nEnter your Position to delete:");
    scanf("%d",&pos);
    delete_at_pos(pos);
    
    printf("The array is after deleted at specific position:");
    display();
    
    return 0;
}
