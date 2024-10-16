#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    char* arr;
};

int isEmpty(struct Stack *sp){
    if (sp->top==-1)        //check if stack is empty
    {
        return 1;
    }else{
        return 0;
    }
}

void push(struct Stack* stack,char paren){
    stack->arr[++stack->top]=paren;
    // stack->top++;
    // printf("top=%d\n",stack->top);
}

void pop(struct Stack* stack){
    // free(stack->arr[stack->top]);
    stack->top--;
}

int checkValidexp(char* exp,struct Stack *parenStack){
    for(int i=0;exp[i]!='\0';i++){
        if (exp[i]=='('){
            push(parenStack,exp[i]);
        }
        else if(exp[i]==')'){
            if (isEmpty(parenStack)){
                printf("Invalid Expression");
                return 0;
            }
            else{
                pop(parenStack);
            }
        }
    }
    if (isEmpty(parenStack)){
        printf("Valid Expression");
        return 1;
    }
    else{
        printf("Invalid expression");
        return 0;
    }
}

int main(){
    //making a stack to push all the "(" and pop it out when ")" is present in the expression
    struct Stack *parenStack;
    parenStack->size=15;
    parenStack->top=-1;
    parenStack->arr=(char*)malloc(parenStack->size*sizeof(char));

    char* exp="(2+3)-(8-2)";   //expression

    int isValid=checkValidexp(exp,parenStack); //check if the expression is valid by checking parenthesis
    printf("\n%d",isValid);
    free(parenStack->arr);
    free(parenStack);

    return 0;
}