#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void append(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    
    if(newnode == NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        newnode->data=val;
        newnode->next=NULL;
        
        if(head == NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void display()
{
    struct node *temp=head;
    
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct node* reverseList(struct node* head) 
{
    struct node *cur=head;
    struct node *prev=NULL;
    struct node *next1=NULL;


    while(cur != NULL)
    {
        next1=cur->next;


        cur->next=prev;
        prev=cur;
        cur=next1;
    }
    head=prev;
    return head;

}

int main()
{
    int a;
    while(1)
    {
        scanf("%d",&a);
        if(a==-1)
        {
            break;
        }
        else
        {
            append(a);
        }
    }
printf("\nTo print the reversed linked list\n");
head=reverseList(head);
display(); 
  return 0;
}
