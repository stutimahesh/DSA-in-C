//Implementing circularQueue using arrays
#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int frontInd; //stores index of first elem of the cirQue
    int backInd; //stores index of the last elem of the cirQue
    int *arr;   //cirQue elements stored in array whose address is stored 
};

int isFull(struct circularQueue* cirQue){
    //backIndex+1 modulus size of array when equal to front Index gives a Overflow Queue
    if ((cirQue->backInd+1)%cirQue->size==cirQue->frontInd){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct circularQueue* cirQue){
    if(cirQue->backInd==cirQue->frontInd){ 
        //if both the front and back index are same then there are no elements in the cirQue
        return 1;
    }else{
        return 0;
    }
}

//traversal through all the elements in the cirQue
void peek(struct circularQueue* cirQue){
    if (isEmpty(cirQue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: \n");
    int i = cirQue->frontInd;
    do {
        printf("At %d index, the element is: %d\n", i, cirQue->arr[i]);
        i = (i + 1) % cirQue->size;
    } while (i != cirQue->backInd);
    printf("\n");
}

//insert or enqueue an element at the back
void encirQue(struct circularQueue* cirQue,int val){
    if (isFull(cirQue)){
        printf("circularQueue is overflow\n");
    }else{
        cirQue->arr[cirQue->backInd]=val; //initialize the value to the backIndex 
        printf("Inserted %d at %d\n",cirQue->arr[cirQue->backInd],cirQue->backInd);
        //increament the backIndex 
        cirQue->backInd=(cirQue->backInd+1)%cirQue->size;
        // peek(cirQue);
    }
}

//remove the first-index element of the Queue
void decirQue(struct circularQueue* cirQue){
    if(isEmpty(cirQue)){
        printf("circularQueue is Empty\n");
    }else{
    // char* del=cirQue->arr[cirQue->frontInd];
        cirQue->frontInd=(cirQue->frontInd+1)%cirQue->size;
        printf("After dequeue the front Index is: %d\n",cirQue->frontInd);
    // free(del);
    }
}

int main(){
    struct circularQueue q;
    q.size=4;
    q.frontInd=q.backInd=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    encirQue(&q,45);
    encirQue(&q,5);
    encirQue(&q,82);
    peek(&q);

     for (int i=0;i<2;i++){
        decirQue(&q);
    }
    peek(&q);

    encirQue(&q,90);
    encirQue(&q,9);
    encirQue(&q,60);
    encirQue(&q,11);
    peek(&q);

    free(q.arr);
    return 0;
}