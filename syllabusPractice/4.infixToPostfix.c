#include <stdio.h>
#include <ctype.h>
#define MAX 10
char stack[15];
int top = -1;

void push(char symbol)
{
    stack[++top] = symbol;
}

char pop()
{
    return stack[top--];
}

int prior(char symbol)
{
    switch (symbol)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[20], char postfix[20])
{
    int i = 0, j = 0;
    push('#');
    while (infix[i] != '\0' && infix[i] != '\n')
    {
        char symbol = infix[i];
        if (isalnum(symbol))
        {
            postfix[j] = symbol;
            j++;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (prior(symbol) <= prior(stack[top]))
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }
        i++;
    }
    i = 0;
    while (stack[top] != '#')
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    pop();
}

int main()
{
    char i[20], p[20];
    printf("Enter infix expression\n");
    fgets(i, 20, stdin);
    infixToPostfix(i, p);
    printf("The prefix expression is\n");
    fputs(p, stdout);
    return 0;
}