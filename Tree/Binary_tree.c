//Binary tree and inorder traversal

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;
struct Node* queue[100];
int front=-1;
int rear=-1;

struct Node* create_node(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void insertion(int val)
{
    if(root==NULL)
    {
        create_node(val);
        return;
    }
    
    struct Node* newnode =create_node(val);
    
    int front=0,rear=0;
    queue[rear] = root;
    
    while(front<=rear)
    {
        struct Node *cur = queue[front++];
        if(cur->left==NULL)
        {
            cur->left = newnode;
            return;
        }
        else
        {
           queue[++rear] = cur->left;
        }
        if(cur->right==NULL)
        {
            cur->right =newnode;
            return;
        }
        else
        {
            queue[++rear] = cur->right;
        }

    }

}
void inorder(struct Node* node)
{
    if(node!=NULL)
    {
       inorder(node->left);
       printf("%d ",node->data);
       inorder(node->right);
    }
}
int main()
{
    int ele;
    root = create_node(100);
    while(1)
    {
        scanf("%d",&ele);
        if(ele==-1)
            break;
        insertion(ele);
    }

    inorder(root);
}


