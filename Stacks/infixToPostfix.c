#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *stack){
    if (stack->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Stack *stack){
    if (stack->top==stack->size){
        return 1;
    }else{
        return 0;
    }
}

void push(struct Stack* stack,char elem){
    if (!isFull(stack)){
        stack->arr[++stack->top]=elem;
        // stack->top++;
    }
    else{
        printf("Stack is overflow");
    }
}

void pop(struct Stack* stack){
    if (isEmpty(stack)){
        printf("Stack is empty cannot pop any element");
    }
    else{
        char popped=stack->arr[stack->top--];
        // stack->top--;
        printf("Popped: %c\n",popped);
    }
}

//function to check if the charecter is operator or not
int isOperator(char ch){
    if (ch== '*'  || ch=='/' || ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}

//presedence function to check precedence of the operators
int precedence(char ch){
    if (ch == '*'  || ch =='/')
        return 3;
    else if(ch =='+' || ch =='-')
        return 2;
    else 
        return 0;
}

char *infixToPosfix(char *infix,struct Stack* stack){
    char *posFix= (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;    //track infix traversal
    int j=0;    //track postfix traversal
    while (infix[i]!='\0'){
        if (!isOperator(infix[i])){
            posFix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stack->arr[stack->top])){
                push(stack,infix[i]);
                i++;
            }
            else{
                posFix[j]=stack->arr[stack->top];
                pop(stack);
                j++;
            }
        }
    }
    while (!isEmpty(stack)){
        posFix[j]=stack->arr[stack->top];
        pop(stack);
        j++;
    }
    posFix[j]='\0';
    return posFix;
}

int main(){
    struct Stack *sp=(struct Stack*)malloc(sizeof(struct Stack));
    sp->size=5;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char *postFixExp;
    char infixExp[]="6+2*8+2";
    postFixExp=infixToPosfix(infixExp,sp);
    printf("Postfix Expression is %s",postFixExp);
    return 0;
}