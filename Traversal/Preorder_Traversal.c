//Preorder Traversal
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int value)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *createtree()
{
    int value;
    
    printf("Enter your node value (-1 for no node):");
    scanf("%d",&value);
    
    if(value == -1)
    {
        return NULL;
    }
    
    struct node *root=createnode(value);
    
    printf("Enter left child of %d\n",value);
    root->left=createtree();
    
    printf("Enter right child of %d\n",value);
    root->right=createtree();
    
    return root;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    printf("Create Binary tree\n");
    root=createtree();
    
    printf("\nInoreder traversal:");
    inorder(root);
    return 0;

    return 0;
}
