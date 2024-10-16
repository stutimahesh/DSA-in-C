#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

int isEmpty(node* stackTop){
    if(stackTop==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    node* p=(node*)malloc(sizeof(node));
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}

void display(node* stackTop){
    while(stackTop!=NULL){
        printf("%d\n____\n",stackTop->data);
        stackTop=stackTop->next;
    }
    printf("\n");
}

node* push(node* stackTop,int val){
    if(isFull()){
        printf("Stack is Full.elements cannot be pushed");
    }else{
        node* p=(node*)malloc(sizeof(node));
        p->data=val;
        p->next=stackTop;
        stackTop=p;
        return stackTop;
    }   
}

node* pop(node* stackTop){
    if(isEmpty(stackTop)){
        printf("Stack is Empty.Cannot pop any element");
    }else{
        node* p=stackTop;
        p=p->next;
        free(stackTop);
        return p;
    }
}

int main(){
    node* top=NULL;
    top=push(top,78);
    top=push(top,54);
    top=push(top,99);
    top=push(top,63);
    display(top);
    top=pop(top);
    display(top);
    return 0;
}