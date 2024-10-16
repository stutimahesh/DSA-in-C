#include <stdio.h>
#include <ctype.h>
#include<math.h>

double stack[15];
int top = -1;

void push(double symbol)
{
    stack[++top] = symbol;
}

double pop()
{
    return stack[top--];
}

double op(char symbol, double opr1, double opr2)
{
    switch (symbol)
    {
    case '+':
        return opr1 + opr2;
    case '-':
        return opr1 - opr2;
    case '*':
        return opr1 * opr2;
    case '/':
        return opr1 / opr2;
    case '^':
        return pow(opr1 , opr2);
    default:
        return 0.0;
    }
}

double evaluation(char postfix[])
{
    int i = 0;
    double a, b, c;

    while (postfix[i] != '\0' && postfix[i] != '\n')
    {
        char symbol = postfix[i];
        if (isdigit(symbol))
        {
            push(symbol - '0');
        }
        else
        {
            b = pop();
            a = pop();
            c = op(symbol, a, b);
            push(c);
        }
        i++;
    }
    double res = pop();
    printf("Answer= %f", res);
}

int main()
{
    char postfix[20];
    printf("Enter postfix expresion\n");
    fgets(postfix, 20, stdin);
    evaluation(postfix);
    return 0;
}