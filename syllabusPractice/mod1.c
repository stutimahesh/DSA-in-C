#include <stdio.h>
#include<stdlib.h>


void main() 
{
 int i,*pi;
 pi=(int*)malloc(sizeof(int)); 
 *pi=1024; 
 printf("an integer =%d",pi); 
 printf("\nvalue of integer =%d",*pi);
 free(pi); 
}