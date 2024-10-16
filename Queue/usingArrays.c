//Implementing Queue using arrays
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int frontInd; //stores index of first elem of the queue
    int backInd; //stores index of the last elem of the queue
    int *arr;   //queue elements stored in array whose address is stored 
};

int isFull(struct Queue* queue){
    if (queue->backInd==queue->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Queue* queue){
    if(queue->frontInd==queue->backInd){ //if both the front and back index are same then there are no elements in the queue
        return 1;
    }else{
        return 0;
    }
}

//traversal through all the elements in the queue
void peek(struct Queue* queue){
    for (int i=queue->frontInd+1;i<queue->backInd;i++){
        printf("At %d index,the element is: %d\n",i,queue->arr[i]);
    }
    printf("\n");
}

//insert or enqueue an element at the back
void enqueue(struct Queue* queue,int val){
    if (isFull(queue)){
        printf("Queue is overflow");
    }else{
        queue->backInd++;
        queue->arr[queue->backInd]=val;
        // peek(queue);
    }
}

//remove the first index element 
void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty");
    }else{
    // char* del=queue->arr[queue->frontInd];
        queue->frontInd=queue->frontInd+1;
    // free(del);
    }
}

int main(){
    struct Queue q;
    q.size=10;
    q.frontInd=q.backInd=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,45);
    enqueue(&q,5);
    enqueue(&q,82);
    enqueue(&q,33);
    enqueue(&q,90);
    peek(&q);
    for (int i=0;i<2;i++){
        dequeue(&q);
    }
    peek(&q);
    return 0;
}