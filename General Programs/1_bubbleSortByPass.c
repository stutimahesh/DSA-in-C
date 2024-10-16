#include <stdio.h>

void printArray(int A[], int n)
{
    printf("\nThe elements in the array are: [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("]\n\n");
}

// in this bubble sort the comparison between index 0-1,1-2,2-3..(n-2)-(n-1) is done.
// the number of passes(stages)=size of array-1
/*
for the array A sorting occurs as:
Pass 1: 12 54 65 7 23 9
        12 54 65 7 23 9
        12 54 7 65 23 9
        12 54 7 23 65 9
        12 54 7 23 9 65     (6-0-1)=5 times in pass 1

Pass 2: 12 54 7 23 9 65
        12 7 54 23 9 65
        12 7 23 54 9 65
        12 7 23 9 54 65     (6-1-1)=4 times in pass 2

Pass 3: 7 12 23 9 54 65
        7 12 23 9 54 65
        7 12 9 23 54 65     (6-2-1)=3 times in pass 3

Pass 4: 7 12 9 23 54 65
        7 9 12 23 54 65     (6-3-1)=2 times in pass 4

Pass 5: 7 9 12 23 54 65     (6-4-1)=1 time in pass 5)
       Since 7 is less than 9 there is no swap
*/

void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) // for number of pass
    {
        printf("Working on Pass %d\n",i+1);
        for (int j = 0; j < n - i - 1; j++) // for comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n); // printing the array before sorting
    bubbleSort(A, n); // function to sort the array
    printArray(A, n); // printing the array after sorting
    
    return 0;
}

/* in adaptive condition he array would already be sorted and there is no need for comparitions

To make the bubble sort ADAPTIVE add "isSorted" int whose value is initialized 0
after gettinf in the pass loop the isSorted value is 1
if the array satisfies the condition of A[j]>A[j+1] then isSorted becomes zero
right after the if condition,inside the comparision "j" loop itself add :
if(isSorted=1) return;
 */