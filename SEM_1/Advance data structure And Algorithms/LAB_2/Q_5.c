//factorial a number
//#include<stdio.h>

int factorial(n){
    if(n==0 | n==1){
        return 1;
    }
    else
        return n*factorial(n-1);
}


int main(){
    int n,ans=1;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        ans = ans*i;
    }
    printf("\n Answer ==> %d",ans);
    ans =factorial(n);
    printf("\n Answer ==> %d",ans);

}