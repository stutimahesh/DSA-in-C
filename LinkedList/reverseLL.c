#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Reverse the linked list
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    // Traverse the list and reverse the pointers
    while (current != NULL)
    {
        next = current->next; // Save next
        current->next = prev; // Reverse the link
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }

    return prev; // New head is the previous node at the end
}

// Display the linked list
void display(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("Value=%d\n", head->val);
        head = head->next;
    }
}

int main()
{
    // Creating nodes
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    // Assign values and link nodes
    p1->val = 1;
    p1->next = p2;
    p2->val = 2;
    p2->next = p3;
    p3->val = 3;
    p3->next = p4;
    p4->val = 4;
    p4->next = p5;
    p5->val = 5;
    p5->next = NULL;

    printf("The values are assigned\nCalling reverse function...\n");

    // Reverse the linked list
    struct ListNode *reversedHead = reverseList(p1);

    // Display reversed list
    printf("After reversing:\n");
    display(reversedHead);

    // Free allocated memory (optional but good practice)
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);

    return 0;
}
