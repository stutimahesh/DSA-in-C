#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack*p){
    if(p->top==p->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct stack *p){
    if(p->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *p,int val){
    if (isFull(p)){
        printf("Stack is full.Cannot push any Element");
    }else{
        p->arr[p->top++]=val;
        // printf("%d\n",p->top++);
        // p->top++;
    }
    printf("pushed\n");
}

void pop(struct stack *p){
    if (isEmpty(p)){
        printf("Stack is empty.Cannot pop any Element");
    }else{
        // free(p->arr[p->top]);
        p->top--;
        printf("Popped\n");
    }
}

void display(struct stack *p){
    for (int i=-1;i<p->top;i++){
        printf("Element %d: %d\n",i+2,p->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));
    push(sp,2);
    push(sp,6);
    push(sp,8);
    push(sp,9);
    display(sp);
    pop(sp);
    display(sp);
    
    free(sp);
    return 0;
}