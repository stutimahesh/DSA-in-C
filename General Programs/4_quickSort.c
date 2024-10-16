#include<stdio.h>

void printArray(int* A,int n){
    printf("The elements of the array are:\n[");
    for (int i=0;i<n;i++){
        printf(" %d",A[i]);
    }
    printf(" ]\n");
}

int partition(int A[],int low,int high){
    int temp;
    int pivot= A[low];
    int i=low+1;
    int j=high;
    do{
        while(A[i]<=pivot){
            i++;
        }

        while (A[j]>pivot){
            j--;
        }

        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);

    //Swap a[low] and a[j]
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}

void quickSort(int *A,int low,int high){
    int partitionIndex; //index of pivot after partition
    if(low<high){
        partitionIndex=partition(A,low,high);
        quickSort(A,low,partitionIndex-1); //sort left subArray
        quickSort(A,partitionIndex+1,high); //sort right subArray
    }
}

int main(){
    int A[]={12,34,7,24,51,9};
    int n=sizeof(A)/sizeof(int);
    printArray(A,n);
    quickSort(A,0,5);
    printArray(A,n);
    return 0;
}