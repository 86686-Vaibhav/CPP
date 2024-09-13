#include<stdio.h>
struct Date{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate){
  ptrDate->day = 15;
  ptrDate->month = 12;
  ptrDate->year = 1990;   
}

void AcceptDate(struct Date *ptr)
{
    printf("Enter Day Month Year = ");
    scanf("%d%d%d",&ptr->day,&ptr->month,&ptr->year);
}
void DisplayDate(struct Date *ptr)
{
    printf("Date = %d-%d-%d\n", ptr->day,ptr->month,ptr->year);
}
int main()
{
    struct Date t1;
    

    AcceptDate(&t1);
    DisplayDate(&t1);

    struct Date t2;
    initDate(&t2);
    DisplayDate(&t2);
    return 0;
    
    
}