#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* ptr){
    int i=1;
    while (ptr!=NULL){
        printf("Element %d: %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
    printf("\n");
}

//Case 1
struct Node* insertAtBegining(struct Node* head,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("After insertion at the begining\n");
    return head;
}

//Case 2
struct Node* insertInBetween(struct Node* head,int value,int index){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    newNode->data=value;
    temp->next=newNode;
    printf("After insertion at the index\n");
    return head;
}

//Case 3
struct Node* insertAtEnd(struct Node* head,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    newNode->data=value;
    int i=0;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    printf("After insertion at the end\n");
    return head;
}

//Case 4
struct Node* insertAfterNode(struct Node* head,struct Node* prevNode,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=prevNode->next;
    prevNode->next=newNode;
    newNode->data=value;
    printf("After insertion after node\n");
    return head;
}

int main(){

    //memory allocation 
    struct Node* head =(struct Node*)malloc(sizeof(struct Node));
    struct Node* sec =(struct Node*)malloc(sizeof(struct Node));
    struct Node* third =(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth =(struct Node*)malloc(sizeof(struct Node));

    //linking head and first node
    head->data=2;
    head->next=sec;

    //linking sec and third node
    sec->data=4;
    sec->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=8;
    fourth->next=NULL;
    
    head=insertAtBegining(head,0);
    printList(head);
    head=insertInBetween(head,7,3);
    printList(head);
    head=insertAtEnd(head,10);
    printList(head);
    head=insertAfterNode(head,fourth,9);
    printList(head);

    return 0;
}