#include <stdio.h>
#include <stdlib.h>

 // initialization of front and rare pointers
struct Node *front = NULL;
struct Node *rare = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node* front){
    printf("Printing the elements of Queue\n");
    int i=1;
    struct Node* f=front;
    while(f!=NULL){
        printf("Element %d: %d\n",i,f->data);
        i++;
        f=f->next;
    }
    printf("\n");
}

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue if full");
    }
    else
    {
        newNode->data=val;
        newNode->next=NULL;
        if(front==NULL){
            front=rare=newNode;
        }
        else{
            rare->next=newNode;
            rare=newNode;
        }
    }
}

int dequeue()
{
    int val=-1;
    struct Node* ptr=front;
    if(front==NULL){
        printf("Queue is Empty");
    }
    else{
        front=front->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}

int main()
{
    enqueue(6);
    enqueue(8);
    enqueue(10);
    enqueue(15);
    traversal(front);
    int removed=dequeue();
    printf("The dequeued element is: %d",removed);
    traversal(front);
    return 0;
}