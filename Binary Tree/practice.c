#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newLL(struct Node* head)
{
    struct Node* trav=head;
    int i=1;
    while(trav->next!=NULL){
        i+=1;
        trav=trav->next;
    }
    int n;
    if(i%2 == 1){
        n=((i/2) + 1);
    }else{
        n=i/2;
    }
    int j=0;
    while(j<n){
        j++;
        head=head->next;
    }
    struct Node* returnNode=head;
    return returnNode;
}

struct Node* merge2LL(struct Node* list1,struct Node* list2)
{
    int i=0;
    struct Node* merged[20]=(struct Node*)malloc(sizeof(struct Node));
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data == list2->data)
        {
            merged[i]->data = list1->data;
            merged[i-1]->next=merged[i];
            i++;
            list1=list1->next;
            list2=list2->next;
        }
        else if(list1->data < list2->data)
        {
            merged[i]->data= list1->data;
            merged[i-1]->next=merged[i];
            list1=list1->next;
            i++;
        }
        else 
        {
            merged[i]->data= list2->data;
            merged[i-1]->next=merged[i];
            list2=list2->next;
            i++;
        }
    }
    while(list1!=NULL)
    {
        merged[i]->data=list1->data;
        merged[i-1]->next=merged[i];
        list1=list1->next;
        i++;
    }
    while(list2!=NULL)
    {
        merged[i]->data=list2->data;
        merged[i-1]->next=merged[i];
        list2=list2->next;
        i++;
    }
    return merged[0];
}





















/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//     // Create a dummy node to simplify the edge cases.
//     struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* current = dummy;  // Pointer to track the current node in the merged list.

//     // Traverse both lists until one of them is empty.
//     while (list1 != NULL && list2 != NULL) {
//         if (list1->val <= list2->val) {
//             current->next = list1;
//             list1 = list1->next;
//         } else {
//             current->next = list2;
//             list2 = list2->next;
//         }
//         current = current->next;
//     }

//     // Append the remaining elements from either list1 or list2.
//     if (list1 != NULL) {
//         current->next = list1;
//     } else {
//         current->next = list2;
//     }

//     // The merged list starts at dummy->next (skipping the dummy node).
//     struct ListNode* head = dummy->next;

//     // Free the dummy node, as it's no longer needed.
//     free(dummy);

//     return head;
// }
