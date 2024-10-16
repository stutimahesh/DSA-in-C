#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node *ptr){
    int i=1;
    while (ptr!=NULL){
        printf("Element %d: %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}

int main(){
    //allocation of memory for LinkedList elements in HEAP
    struct Node* head =(struct Node*)malloc(sizeof(struct Node));
    struct Node* sec =(struct Node*)malloc(sizeof(struct Node));
    struct Node* third =(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth =(struct Node*)malloc(sizeof(struct Node));

    //linking head and first node
    head->data=66;
    head->next=sec;

    //linking sec and third node
    sec->data=3;
    sec->next=third;

    third->data=0;
    third->next=fourth;

    fourth->data=23;
    fourth->next=NULL;

    traversal(head);
    
    return 0;
}