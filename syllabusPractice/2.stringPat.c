#include<stdio.h>
#include<stdlib.h>
int flag=0;
void stringMatch(char str[50],char pat[25],char rep[25],char ans[50])
{
    int c,m,i,j,k;
    c=m=i=j=k=0;
    while (str[c]!='\0')
    {
        if (str[m] == pat[i])
        {
            m++;i++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(j=0;rep[j]!='\0';j++,k++)
                {
                    ans[k]=rep[j];
                }
                i=0;
                c=m;
            }
        }
        else
        {
            ans[k]=str[c];
            k++;c++;
            m=c;
            i=0;
        }
    }
    ans[k]='\0';
}

int main()
{
    char s[50],p[25],r[25],a[50];
    printf("\nEnter the string\n");
    fgets(s,50,stdin);
    printf("\nEnter the pattern string\n");
    fgets(p,25,stdin);
    printf("\nEnter the replace string\n");
    fgets(r,25,stdin);
    stringMatch(s,p,r,a);
    if(flag==1)
    {
        printf("\nThe resultant string is:\n");
        fputs(a,stdout);
    }
    else
    {
        printf("No pattern found");
    }
    return 0;
}