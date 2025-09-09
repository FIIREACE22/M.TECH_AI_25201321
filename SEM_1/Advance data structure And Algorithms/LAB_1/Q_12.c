#include<stdio.h>
#include<math.h>
int main(){
    int n,a=0,b,c=0,i;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);

    for(i=2 ;i<=n/2; i++ ){
        if(n%i==0){
            printf("\n Number is prime number");
        }
        else{
            printf("\n Number is not prime number");
        }
    }

}


