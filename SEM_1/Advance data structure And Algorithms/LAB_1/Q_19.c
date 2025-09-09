//Sum of Digits using Recursion
int sum(n){
    if (n==0){
        return 0;
    }
    return n%10 + sum(n/10);
}

int main(){
    int n,a=0,b,c=0,i;
    printf("\n Enter value n ==> ");
    scanf("%d",&n);

    printf("\n sum of number %d's digit is ==> %d",n,sum(n));
}
