#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node* head){
    struct Node* p=head;
    int i=1;
    // printf("Element %d: %d\n",i,p->data);
    // i++;
    // p=p->next;
    do{
        printf("Element %d: %d\n",i,p->data);
        i++;
        p=p->next;
    }while (p!=head);
    printf("\n");
}

struct Node* insertNode(struct Node* head,struct Node* prevNode,struct Node* nodeAfter,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    // struct Node* q=head;
    newNode->data=val;
    newNode->next=nodeAfter;
    prevNode->next=newNode;
    printf("\nInserting node\n");
    return head;
}

struct Node* insertNodeAtBegin(struct Node* head,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* q=head;
    q=q->next;
    while(q->next!=head){
        q=q->next;
    }
    newNode->data=val;
    newNode->next=head;
    q->next=newNode;
    head=newNode;
    printf("\nInsert at the begining\n");
    return head;
}

struct Node* deleteNode(struct Node* head,int val){
    struct Node* p=head;
    struct Node* q=head->next;
    do{
        p=p->next;
        q=q->next;
    }while(q->data!=val);
    p->next=q->next;
    free(q);
    printf("\nDeleting node\n");
    return head;
}


int main(){
    struct Node* head;
    struct Node* sec;
    struct Node* third;
    struct Node* fourth;

    
    head=(struct Node*)malloc(sizeof(struct Node));
    sec=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=3;
    head->next=sec;

    sec->data=5;
    sec->next=third;

    third->data=7;
    third->next=fourth;

    fourth->data=9;
    fourth->next=head;

    traversal(head);
    head=insertNode(head,third,fourth,8);
    traversal(head);
    head=insertNodeAtBegin(head,1);
    traversal(head);
    head=deleteNode(head,8);
    traversal(head);
    return 0;
}