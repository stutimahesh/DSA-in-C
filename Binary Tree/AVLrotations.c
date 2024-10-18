#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node *treeHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

int getheight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct node *createNode(int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(n->left) - getheight(n->right);
    }
}

struct node *rightRotate(struct node *A)
{
    /*
                 A                      B
                / \                    /  \
               B   C       __\        D    A
              / \            /       /    / \
             D   E                  F    E   C
            /
           F
    */
    struct node *B = A->left;
    struct node *E = B->right;

    B->right = A;
    A->left = E;

    A->height = (max(getheight(A->left), getheight(A->right)) + 1);
    B->height = (max(getheight(B->left), getheight(B->right)) + 1);
    return B;
}

struct node *leftRotate(struct node *A)
{
    /*
                    A                     C
                   / \                   /  \
                  B   C       __\       A    F
                     / \        /      / \    \
                    E   F             B   E    G
                         \
                          G
    */
    struct node *C = A->right;
    struct node *E = C->left;

    C->left = A;
    A->right = E;

    A->height = (max(getheight(A->left), getheight(A->right)) + 1);
    C->height = (max(getheight(C->left), getheight(C->right)) + 1);
    return C;
}

struct node *insert(struct node *n, int key)
{
    if (n == NULL)
    {
        return (createNode(key));
    }

    if (key < n->key)
    {
        insert(n->left, key);
    }
    else if (key > n->key)
    {
        insert(n->right, key);
        return n;
    }
    
    n->height = 1 + max(getheight(n->left),getheight(n->right));
    int bf = getBalanceFactor(n); 

    //Left Left case
    if(bf > 1 && key < n->left->key)
    {
        rightRotate(n);
    }
    //Right Right case
    if(bf < -1 && key > n->right->key)
    {
        leftRotate(n);
    }
    //Right Left case
    if(bf < -1 && key < n->right->key)
    {
        n->right=rightRotate(n->right);
        leftRotate(n);
    }
    //Left Right case
    if(bf > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        rightRotate(n);
    }
    return n;
}

int main()
{
    struct Node* root= NULL;
    root=insert(root, 45);
    root=insert(root, 8);
    root=insert(root, 5);
    root=insert(root, 16);
    root=insert(root, 9);
    root=insert(root, 22);
    return 0;
}