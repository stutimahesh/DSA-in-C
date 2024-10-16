/*
BINARY SEARCH TREE
->inOrder raversal of BST gives an asending sorted array
->allnodes of left subtree are lesser than all the nodes on right subtree
->left and right subtrees are BST
->there are no duplicate nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if(root->data<key)
    {
        return search(root->right,key);
    }
    else 
    {
        return search(root->left,key);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
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

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct node *p = createNode(6);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(5);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(12);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    if (isBST(p))
    {
        printf("It is a BST\n");
        inOrderTraversal(p);
    }
    else
    {
        printf("Not a BST\n");
        inOrderTraversal(p);
    }

    struct node *n = search(p, 7);
    printf("\n%d", n->data);

    return 0;
}
