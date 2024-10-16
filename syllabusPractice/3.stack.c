#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int stack[MAX];
int top = -1;
int flag = 1;

void push(int val)
{
    if (top == (MAX - 1))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        stack[++top] = val;
        printf("%d is pushed\n\n", stack[top]);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        int popped = stack[top--];
        printf("%d is popped\n\n", popped);
    }
}

void palindrome()
{
    printf("The stack contents are\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    printf("On reversing stack contents we get\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
    for (int i = 0; i <= top; i++)
    {
        if (stack[i] != stack[top - i])
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a paindrome\n\n");
    }
}

void display()
{
    printf("The stack contents are\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    printf("\n\n");
}

int main()
{
    int ch;
    int val;
    do
    {
        printf("__________________________\n");
        printf("1.PUSH\n2.POP\n3.Check PALINDROME\n4.DISPLAY\n5.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be pushed\n");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;

        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong input");
        }
    } while (ch != 5);
    return 0;
}