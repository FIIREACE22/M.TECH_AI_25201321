int factorial(n){
    if(n==0 | n==1){
        return 1;
    }
    else
        return n*factorial(n-1);
}

int main(){
    int n,ans;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);

    ans =factorial(n);
    printf("\n Answer ==> %d",ans);
}

