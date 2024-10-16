#include <stdio.h>
#include <stdlib.h>

struct DAY
{
    char *dayName;
    int date;
    char *activity;
};

void create(struct DAY *day)
{
    day->dayName = (char *)malloc(10 * sizeof(char));
    day->activity = (char *)malloc(10 * sizeof(char));
    printf("\nEnter the day name\n");
    scanf("%s", day->dayName);
    printf("\nEnter the date\n");
    scanf("%d", &day->date);
    printf("\nMention the activity\n");
    scanf("%s", day->activity);
}

void read(struct DAY *calender, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the details for the day %d", i + 1);
        create(&calender[i]);
    }
}

void display(struct DAY *calender, int size)
{
    printf("ACTIVITY LIST\n___________________________________________________\n____________________________________________\n\n");
    printf("NAME\t\t\tDATE\t\tACTIVITY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\t\t\t%d\t\t%s\n\n", calender[i].dayName, calender[i].date, calender[i].activity);
    }
    printf("_______________________________________________\n");
}

void freeMemory(struct DAY *calender, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(calender[i].dayName);
        free(calender[i].activity);
    }
}

int main()
{
    int size = 3;
    struct DAY *cal = (struct DAY *)malloc(sizeof(struct DAY) * size);

    read(cal, size);
    display(cal, size);
    freeMemory(cal, size);
    free(cal);

    return 0;
}