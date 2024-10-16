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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data)
        {
            return 0;
        }
        prev=root;
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

    return 0;
}

//Working of code
/*
1)Initial Call: The isBST function is first called with root = 6 and prev = NULL.

2)Check Left Subtree (root = 4):
    The function moves left to node 4, and again recursively checks the left subtree.

3)Check Left Subtree (root = 2):
    It moves further left to node 2. Since node 2 has no left child, it returns 1 (valid).
The function then compares node 2 with prev = NULL (this is the first comparison, so it’s valid).
The function sets prev = 2 and checks the right subtree (which is also empty, so it returns 1).

4)Compare node 4 with prev (2):
    The function moves back to node 4 and compares it with prev = 2. Since 4 > 2, it’s valid.
The function sets prev = 4 and proceeds to check node 4’s right subtree (node 5).

5)Check node 5:
    Node 5 has no children, so it’s compared with prev = 4. Since 5 > 4, it’s valid. The function sets prev = 5.

6)Compare node 6 with prev (5):
    The function returns to node 6 and compares it with prev = 5. Since 6 > 5, it’s valid.
The function sets prev = 6 and checks node 6’s right subtree (starting with node 9).

7)Check Right Subtree (similar process continues for nodes 9, 7, and 12).

The tree is valid, and the function returns 1.

This step-by-step in-order traversal ensures that the tree satisfies all the properties of a BST.

*/