#include<stdio.h>
#include<stdlib.h>
typedef struct myArray{
    int total_size;
    int used_size;
    int *ptr;
}Arr;

void createArray(Arr* a,int tSize,int uSize){
    //acts like a constructor(in c++) in C
    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr=(int *)malloc(tSize*sizeof(int));
}

void showArray(Arr* b){
    //displays the array using pointer accesing each element
    for(int i=0; i < b->used_size;i++){
        printf("%d\n",(b->ptr)[i]);
    }
}

void setArray(Arr *c){
    //takes the elemnts as input from used (the value at address c)
    int n,i;
    for(i=0;i<c->used_size;i++){
        printf("Enter element %d: \t",i);
        scanf("%d",&n);
        (c->ptr)[i]=n;
    }
} 

int main(){
    Arr marks;
    createArray(&marks,5,2); 
    setArray(&marks);
    showArray(&marks);
    return 0;
}