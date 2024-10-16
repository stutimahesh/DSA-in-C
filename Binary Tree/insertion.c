#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void display(node *root)
{
    // printf("\n");
    if (root != NULL)
    {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

node *insertion(node *root, int key)
{
    node *mainR = root;
    node *prev = NULL;

    printf("\nAfter insertion");
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("duplicate nodes cannot exist,insertion not possible");
            return mainR;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    node *new = createNode(key);
    if (prev->data < key)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
    }

    
    return mainR;
}

int main()
{
    node *p = createNode(6);
    node *p1 = createNode(4);
    node *p2 = createNode(9);
    node *p3 = createNode(2);
    node *p4 = createNode(5);
    node *p5 = createNode(7);
    node *p6 = createNode(12);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    if (isBST(p))
    {
        printf("It is a BST\n");
        display(p);
    }
    else
    {
        printf("Not a BST\n");
        display(p);
    }
    printf("\nCalling insertion function");
    node *q = insertion(p, 11);
    printf("\nprinting after insertion\n");
    display(q);

    return 0;
}