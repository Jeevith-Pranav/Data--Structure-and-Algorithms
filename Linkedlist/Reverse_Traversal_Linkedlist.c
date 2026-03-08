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


void rev_disp(struct node *temp)
{
    if(temp==NULL)
    return;
  
    rev_disp(temp->next);
    printf("%d ",temp->data);
}


void sort()
{
    struct node *temp=head;
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
    
    printf("\nTo Print in same order\n");
    display();
    
printf("\nTo Print in reverse order\n");
rev_disp(head);
    
    return 0;
}
