//Queue Using Stack
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front =-1,rear=-1;

int main()
{
    int n,value;
    printf("enter the no of elements to insert (max %d):",MAX);
    scanf("%d",&n);
    if(n>MAX)
    {
        printf("Queue is Overflow!! Add panna mudiyathu");
        return 0;
    }
     if(n<=0)
     {
         printf("Queue is Underflow");
         return 0;
     }
    
    front =0;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        queue[++rear]=value;
    }
    printf("Queue Stored in array:");
    
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}
