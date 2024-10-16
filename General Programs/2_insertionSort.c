#include <stdio.h>

void printArray(int A[], int n)
{
    printf("\nThe elements of the array are:\n[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("]\n");
}


void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        // Lopp for each pass
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            // printf("%d",j);
            A[j + 1] = A[j];
            printArray(A,n);
            j--; // condition will become false when j=-1 therefore after loop A[j+1]
        }
        A[j + 1] = key;
        //  printf("\n");
    }
}


int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(A) / sizeof(int);
    printf("%d", n);
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}