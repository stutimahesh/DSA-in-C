#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    //Creating a new node
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode; //return created node
}

void preOrder(struct node* root){
    while(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    
    struct node *p1=createNode(3); //Root node
    struct node *p2=createNode(5);
    struct node *p3=createNode(7);
    struct node *p4=createNode(9);
/*
            3
           /\
          5  7
         /  
        9
*/

    // Linking the root node with left and right children
    p1->left=p2;
    p1->right=p3;
    
    p2->left=p4;

    printf("\nPre order Traversal:\n");
    preOrder(p1);
    printf("\nPost order Traversal:\n");
    postOrder(p1);
    printf("\nIn order Traversal:\n");
    inOrder(p1);
    return 0;
}