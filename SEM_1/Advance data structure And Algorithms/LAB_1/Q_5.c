float calculator(float a , float b){
    char ch;
    float ans;
    printf("\n Enter operation you want to perform +,-,*,/==> ");
    scanf("%s",&ch);
    switch(ch){
        case '+' :ans = a+b;
                  break;
        case '-' :ans = a-b;
                  break;
        case '*' :ans = a*b;
                  break;
        case '/' :ans = a/b;
                  break;
        default : printf("Please Enter Valid Input.....");
                    return 0;
                  break;
    }
    return ans;
}

int main(){
    float a,b,ans;
    printf("\n Enter value a ==> ");
    scanf("%f",&a);
    printf("\n Enter value b ==> ");
    scanf("%f",&b);

    ans = calculator(a,b);
    printf("\n Answer ==> %f",ans);
}
