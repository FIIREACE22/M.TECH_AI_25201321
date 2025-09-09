
#include<stdio.h>

int main(){
    int n,a=0,b,c,i;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);
    c=n;
    while(n>0){
        b = n%10;
        n=n/10;
        a=a*10 + b;
    }
    if(c==a)
        printf("Given number is pelindrome");
    else
        printf("Given number is not pelindrome...");
}
