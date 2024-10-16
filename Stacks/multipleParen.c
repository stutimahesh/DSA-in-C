#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *sp){
    if(sp->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(stack *sp,char paren){
    sp->arr[++sp->top]=paren;
}

int pop(stack *sp,char paren){
    if (isEmpty(sp)){
        printf("Stack is underflow\n");
        return 0;
    }else{
        if (sp->arr[sp->top]==paren){
            sp->top--;
            return 1;
        }
        else{
            // printf("Invalid Expression");
            return 0;
        }
    }
}

void checkValid(stack* sp,char *exp){
    int check;
    for (int i=0;exp[i]!='\0';i++){
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            check=pop(sp,exp[i]);
        }
    }
    if (isEmpty(sp)|| check==0){
        printf("Valid expression\n");
    }
    else{
        printf("Invalid expression\n");
    }
}

int main(){
    stack *multiParen=(stack*)malloc(sizeof(stack));
    multiParen->size=10;
    multiParen->top=-1;
    multiParen->arr=(char*)malloc(multiParen->size*sizeof(char));

    char *exp;
    exp="{[6-2]-[3-2]+(2+[2=4])}";
    checkValid(multiParen,exp);
    return 0;
}