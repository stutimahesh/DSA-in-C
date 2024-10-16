#include <stdio.h>
#include<stdlib.h>
#define MAX 4
int front = 0, rear = -1, count = 0, queue[MAX];

void insert(int ch)
{
    if (count == (MAX - 1))
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        rear = ((rear + 1) % MAX);
        queue[rear] = ch;
        printf("%d inserted\n", queue[rear]);
        count++;
    }
}

void delete()
{
    if (count == 0)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        int del = queue[front];
        front = ((front + 1) % MAX);
        printf("%d deleted\n", del);
        count--;
    }
}

void display()
{
    if (count == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int f = front;
        for (int i = 0; i < count; i++)
        {
            printf("%d\n", queue[f]);
            f = ((f + 1) % MAX);
        }
    }
}

int main()
{
    int ch, item;
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    } while (ch != 4);
    return 0;
}