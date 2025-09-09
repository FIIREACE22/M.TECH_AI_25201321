#include<stdio.h>

int main(){

    int n,total_bill=0;
    printf("\n Enter no. of units used ==> ");
    scanf("%d",&n);
    if(n <= 100){
        total_bill = total_bill + 5*n;

    }
    else if(n>100 && n<=200){
        total_bill = total_bill + 5*100 + 7*(n-100);
    }
    else{
        total_bill = total_bill + 5*100 + 7*100 + 10*(n-200) ;
    }

    printf("Total_bil ==> %d",total_bill);
}
