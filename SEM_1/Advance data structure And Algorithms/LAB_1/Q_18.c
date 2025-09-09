//GCD (Greatest Common Divisor) using Recursion
int gcd(int a , int b){
    if (b==0){
        return a;
    }
    return gcd(b , a%b);
}

int main(){
    int n1,n2,ans;
    printf("\n Enter number1 ==> ");
    scanf("%d",&n1);
    printf("\n Enter number2 ==> ");
    scanf("%d",&n2);
    //ans =gcd(n1,n2);
    printf("GCD of %d and %d is %d..",n1,n2,gcd(n1,n2));
}
