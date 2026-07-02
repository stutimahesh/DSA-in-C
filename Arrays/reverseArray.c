#include<stdio.h>
int main(){
    int nums[10],n;
    printf("enter the length of array of numbers\n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("Original array\n");
    for (int i=0;i<n;i++){
        printf("%d\t",nums[i]);
    }
    int m=n/2;
    for (int i=0;i<m;i++){
        int temp;
        temp=nums[i];
        nums[i]=nums[n-i-1];
        nums[n-i-1]=temp;
    }
    printf("\nReversed array\n");
    for (int i=0;i<n;i++){
        printf("%d\t",nums[i]);
    }

    return 0;
}