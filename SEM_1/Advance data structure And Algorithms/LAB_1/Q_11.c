#include<stdio.h>

int main(){
    int n,a=0,b,c=0,i;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);

    while(n>0){
        b = n%10;
        n=n/10;
        a=a + b;
    }
    printf("sum of digit ==> %d",a);
}


