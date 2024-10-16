#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* inOrderPredecessor(struct Node* root){
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
    }

    // first search for node
    if (value < root->data)
    {
        deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        deleteNode(root->right, value);
    }
    // Deletion stratergy when the node is found
    else
    {
        struct Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
    return root;
}