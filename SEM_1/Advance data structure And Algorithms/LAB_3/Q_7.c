/*Define a structure Date with fields day, month, and year. Write a program to input two dates
and determine which date is earlier.*/

struct Date{
    int day;
    int month;
    int year;
};
int main(){
    struct Date d1,d2;
    printf("Enter the first date (dd mm yyyy)-->");
    scanf("%d %d %d",&d1.day,&d1.month,&d1.year);
    printf("Enter the second date (dd mm yyyy)-->");
    scanf("%d %d %d",&d2.day,&d2.month,&d2.year);
    if(d1.year < d2.year){
        printf("The earlier date is %02d/%02d/%04d\n",d1.day,d1.month,d1.year);
    }
    else if(d1.year > d2.year){
        printf("The earlier date is %02d/%02d/%04d\n",d2.day,d2.month,d2.year);
    }
    else{
        if(d1.month < d2.month){
            printf("The earlier date is %02d/%02d/%04d\n",d1.day,d1.month,d1.year);
        }
        else if(d1.month > d2.month){
            printf("The earlier date is %02d/%02d/%04d\n",d2.day,d2.month,d2.year);
        }
        else{
            if(d1.day < d2.day){
                printf("The earlier date is %02d/%02d/%04d\n",d1.day,d1.month,d1.year);
            }
            else if(d1.day > d2.day){
                printf("The earlier date is %02d/%02d/%04d\n",d2.day,d2.month,d2.year);
            }
            else{
                printf("Both dates are the same: %02d/%02d/%04d\n",d1.day,d1.month,d1.year);
            }
        }
    }
}