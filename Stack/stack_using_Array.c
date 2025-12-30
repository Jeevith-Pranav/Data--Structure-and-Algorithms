//Stack using Array
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

int main()
{
    
    int n,value;
    
    printf("Enter your Elements to insert (Max %d) :",MAX);
    scanf("%d",&n);
    
    
    if(n > MAX)
    {
        printf("Stack Overflow Too Many Elements");
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        stack[++top]=value;
    }
    printf("\nStack stored in array:\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}
