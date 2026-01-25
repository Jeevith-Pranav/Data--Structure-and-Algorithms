#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Create new node */
struct node* createNode(int value)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Insert into BST */
struct node* insert(struct node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* BFS / Level Order Traversal */
void BFS(struct node* root)
{
    if (root == NULL)
        return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

/* Main function */
int main()
{
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBFS (Level Order Traversal): ");
    BFS(root);

    return 0;
}
