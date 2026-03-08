//Stack Using LinkedList
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *top = NULL;


void push(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    
    
    if(newnode == NULL)
    {
        printf("Memory is not found");
    }
    else
    {
        if(top == NULL)
        {
            top=newnode;
        }
        else
        {
            newnode->next=top;
            top = newnode;
        }
    }
}

void display()
{
    struct node *temp=top;
    
    while(temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}


void pop()
{
    struct node *temp = top;
    if(top == NULL)
    {
        printf("Stack is underflow");
    }
    else
    {
        if(top -> next == NULL)
        {
            top=NULL;
            free(top);
        }
        else
        {
            top=top->next;
            free(temp);
        }
    }
}

int main()
{
    int val;
    while(1)
    {
        scanf("%d",&val);
        if(val == -1)
        break;
        
        push(val);
    }
    display();
    printf("Pop the top element %d\n",top->data);
    pop();
    
    printf("Elements after pop\n");
    display();
}

