#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char name[20];
    int rollNo;
    float percentage;
}Student;

int main(){
    int n;  //number of students
    printf("Enter the number of students: ");
    scanf("%d",&n);

    Student *candidates=(Student *)malloc(n*sizeof(Student)); //allocate memory for candidates
    if (candidates==NULL){
        printf("Memory allocation failed");
        return 1;
    }
    //input data
    for (int i=0;i<n;i++){
        printf("\n*********\nCanditade %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",candidates[i].name);
        printf("\nEnter roll no. : ");
        scanf("%d",&candidates[i].rollNo);
        printf("\nEnter percentage : ");
        scanf("%f",&candidates[i].percentage);

    }
    //display data
    for (int i=0;i<n;i++){
        printf("\n*********\nCanditade %d\n",i+1);
        printf("Name : %s\n",candidates[i].name);
        printf("Roll No : %d\n",candidates[i].rollNo);
        printf("Percentage : %f\n",candidates[i].percentage);

    }
    return 0;
}


// #include<stdio.h>
// #include<string.h>
// typedef struct Example{
//     int num;
//     char name[20];
// }ex;
// void main(){
//     struct Example example;
//     example.num=6;
//     strcpy(example.name,"String");
//     printf("%d , %s\n",example.num,example.name);
//     ex *pe=&example;
//     pe->num=100;
//     strcpy(pe->name,"Str2");
//     printf("%d\n%s\n",pe->num,pe->name);
// } 