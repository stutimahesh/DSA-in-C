//Program on insertion and deletion of elements in array
#include<stdio.h>

void display(int a[],int n){
    for (int j=0;j<n;j++){
        printf("%d\t",a[j]);
    }
}
void insertion1(int a[],int num,int pos,int capacity){
    if (pos>capacity){
        printf( "Not posible");
    }else{
        //size=4
        int temp=a[pos];
        a[pos]=num;
        a[4]=temp;
        for (int i=0;i<5;i++){
            printf("%d\t",a[i]);
        }
    }
    printf("\n");
}

void insertion2(int b[],int num,int pos,int capacity,int size){
    if (pos>capacity){
        printf( "Not posible");
    }else{
        for (int i=size;i>pos-1;i--){
            b[i]=b[i-1];
        }
        b[pos]=num;
        for(int i=0;i<6;i++){
            printf("%d\t",b[i]);
        }
    }
    printf("\n");
}

void deletion(int c[],int pos){
    for (int i=pos;i<5;i++){
            c[i]=c[i+1];
        }
    for(int i=0;i<5;i++){
        printf("%d\t",c[i]);
        }
}

int main(){
    int arr[10]={2,6,78,11};
    display(arr,4);
    int n,p;
    printf("\n Enter the number and the position in which the no shld be inserted: \n");
    scanf("%d %d",&n,&p);
    int max=sizeof(arr)/sizeof(int);
    printf("The size of array= %d\n",max);
    insertion1(arr,n,p,max);
    insertion2(arr,20,p,max,5);
    deletion(arr,p);
    return 0;
}