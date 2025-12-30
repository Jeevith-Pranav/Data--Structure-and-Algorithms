//Stack using Linked list
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

int main()
{
    int n,val;
    
    printf("Enter the number of elelemnts (max %d):",MAX);
    scanf("%d",&n);
    
    if(n>MAX)
    {
        printf("The Stack is Overflow");
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&stack[i]);
        top++;
    }
    
    //printf("To Pop the element in stack");
    if(top == -1)
    {
        printf("Stack is under flow");
        return 0;
    }
    else
    {
        printf("\nPopped Element:%d\n",stack[top]);
        top--;
    }
    

    printf("The Stack After the Pop:");
    if(top == -1)
    {
    printf("The Stack is empty");
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}
