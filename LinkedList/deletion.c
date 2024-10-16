#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* ptr){
    int i=1;
    while (ptr!=NULL){
        printf("Element %d: %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
    printf("\n");
}

//Case 1
struct Node* deleteFirstNode(struct Node* head){
    struct Node* temp=head;
    head=head->next;
    free(temp);
    printf("Deletion of first node\n");
    return head;
}

//Case 2
struct Node* deleteNodeInBetween(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    printf("Deletion of node in between\n");
    return head;
}

//Case 3
struct Node* deleteLastNode(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("Deletion of node at the end\n");
    return head;
}

int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* sec=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=11;
    head->next=sec;

    sec->data=12;
    sec->next=third;

    third->data=13;
    third->next=fourth;

    fourth->data=14;
    fourth->next=fifth;

    fifth->data=15;
    fifth->next=NULL;

    head=deleteFirstNode(head);
    display(head);
    head=deleteNodeInBetween(head,2);
    display(head);
    head=deleteLastNode(head);
    display(head);


    return 0;
}