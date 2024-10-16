#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* ptr;
}node;

void display(node *list){
    int i=1;
    while(list!=NULL){
        printf("Element %d : %d\n",i,list->val);
        i++;
        list=list->ptr;
    }
    printf("\n");
}

node * insertionAtBegining(node* head,int data){
    node* new=(node *)malloc(sizeof(node));
    new->val=data;
    new->ptr=head;
    printf("After insertion at the begining\n");
    display(new);

    return new;
}

node* insertAtIndex(node* head,int data,int index){
    node* p=(node*)malloc(sizeof(node));    //node to be inserted with value "data" and at index "index"
    node *initial=head;
    int i=0;

    p->val=data; //initialize the value 
    while (i!=index-1){ //traverse through the linked list till index-1
        i++;
        head=head->ptr;
    }
    p->ptr=head->ptr;
    head->ptr=p;
    printf("After insertion at the index\n");
    display(initial);
    return initial;
}

node* insertionAtEnd(node *p,int data){
    node* new=(node*)malloc(sizeof(node));
    node* q=p;
    new->val=data;
    while (q->ptr!=NULL){
        q=q->ptr;
    }
    q->ptr=new;
    new->ptr=NULL;
    printf("After insertion at the end\n");
    display(p);
    return p;
}

int main(){
     //dynamic allocation
     node* head=(node *)malloc(sizeof(node));
     node* sec=(node *)malloc(sizeof(node));
     node* third=(node *)malloc(sizeof(node));
     node* fourth=(node *)malloc(sizeof(node));

     head->val=4;
     head->ptr=sec;

     sec->val=6;
     sec->ptr=third;

     third->val=8;
     third->ptr=fourth;

     fourth->val=10;
     fourth->ptr=NULL;

    head=insertionAtBegining(head,2);
    node *h=insertAtIndex(head,7,3);
    h=insertionAtEnd(h,12);

    return 0;
}