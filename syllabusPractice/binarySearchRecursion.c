#include<stdio.h>
#include<stdlib.h>

int compare(int x,int y){
    if (x<y) return -1;
    else if(x==y) return 0;
    else return 1;
}

int binSearch(int list[],int searchNum,int posLeft,int posRight){
    int middle=0;
    if(posLeft<posRight){
        middle=((posLeft+posRight)/2);
        printf("%d\n",middle);
        switch(compare(list[middle],searchNum)){
            case -1:binSearch(list,searchNum,middle+1,posRight);
            case 0:return middle;
            case 1: binSearch(list,searchNum,posLeft,middle-1);
        }
    }
    return 0;
}


int main(){
    int nums[]={1,3,5,6,7,9};
    int val=3;
    int position=binSearch(nums,val,0,5);
    if(position==0){
        printf("Could not find value");
    }
    printf("The value is at position %d",position);
    return 0;
}