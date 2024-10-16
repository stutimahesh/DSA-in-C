#include <stdio.h>

void tower(int n, char src, char temp, char dest)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        tower(n - 1, src, dest, temp);
        printf("Move %d from %c to %c\n", n, src, dest);
        tower(n - 1, temp, src, dest);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    return 0;
}