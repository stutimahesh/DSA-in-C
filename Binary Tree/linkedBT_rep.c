// #include <stdio.h>
// #include<malloc.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node* createNode(int val){
//     //Creating a new node
//     struct node* newNode=(struct node*)malloc(sizeof(struct node));
//     newNode->data=val;
//     newNode->left=NULL;
//     newNode->right=NULL;
//     return newNode; //return created node
// }

// int main()
// {
    
//     struct node *p1=createNode(3); //Root node
//     struct node *p2=createNode(5);
//     struct node *p3=createNode(7);
//     struct node *p4=createNode(9);


//     // Linking the root node with left and right children
//     p1->left=p2;
//     p1->right=p3;
    
//     p2->left=p4;

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void inOrderTraversal(struct node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

int main(){
    struct node* branches[5];
    for (int i=0;i<5;i++){
        branches[i]=createNode(i);
    }
    branches[0]->left=branches[1];
    branches[0]->right=branches[2];
    branches[1]->right=branches[3];
    branches[2]->left=branches[4];

    inOrderTraversal(branches[0]);
    return 0;
}