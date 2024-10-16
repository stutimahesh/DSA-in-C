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

//MY CODE
// void selectionSort(int *A, int n)
// {
//     printf("Running Selection sort\n");
//     int minTerm = A[0];
//     for (int i = 0; i < n ; i++)
//     {
//         for (int j = 1; j < n - i ; j++)
//         {
//             if (A[i] > A[i + j])
//             {
//                 minTerm = A[i + j];
//                 A[i + j] = A[i];
//                 A[i] = minTerm;
//                 //printArray(A,n);
//             }
//         }
//     }
// }

void selectionSort(int *A,int n){
    //there will be todal n-1 passes to sort
    int indexOfMin;
    for(int i=0;i<n-1;i++){
        indexOfMin=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[indexOfMin]){
                indexOfMin=j;
            }
        }
        int temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp;
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(A) / sizeof(int);
    printf("%d", n);
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}