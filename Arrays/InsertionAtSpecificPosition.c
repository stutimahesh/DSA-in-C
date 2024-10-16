//Program to insert an elem in an array at a specific position
#include<stdio.h>
#include<string.h>

void main(){
   
    
    int nums[5],m=0,a;
    printf("Enter the no of elements\n");
    printf("Press 's' if you want to stop\n");
    scanf("%d",&a); //input number of elements needed in the array
    
    // int n=sizeof(nums)/sizeof(int);
    printf("Enter the elements: \n");
    for (int i=0;i<a;i++){
        scanf("%d",&nums[i]); //enter elements one by one in each position
        printf("");
        char string[4];
    }
    printf("The elements are: \n");
    for(int i=0;i<a;i++){
        printf("%d\n",nums[i]); //print the elements
    }

    //input the element to be inserted and also the position req
    int num,p;
    printf("Enter the element to be inserted: ");
    scanf("%d",num);
    printf("\nEnter the position: ");
    scanf("%d",p);
    a=a-1;
    for (int i=a;i>=p-1;i--){
        nums[i+1]=nums[i];
    }
    nums[p]=num;
    printf("the new set of elements are: \n");
    a=a+2;
    for (int i=0;i<a;i++){
        printf("%d",nums[i]);
    }    

}