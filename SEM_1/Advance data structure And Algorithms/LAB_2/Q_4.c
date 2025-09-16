//check Even And Odd
#include<stdio.h>

int main(){
    int n;
    printf("Enter number--> ");
    scanf("%d",&n);
    if(n % 2 == 0)
        printf("%d is even..",n);
    else
        printf("%d is odd...",n);

    printf("\n\n\n");
//with betwise and
    if(!(n&1)){
        printf("%d is even..",n);
    }
    else
        printf("%d is odd...",n);

}
