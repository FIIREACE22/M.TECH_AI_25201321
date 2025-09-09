void max(a,b,c){
    if(a>b){
        if(a>c){
            printf("a = %d is largest number",a);
        }
        else{
            printf("c = %d is largest number",c);
        }
    }
    if(b>a){
        if(b>c){
            printf("b = %d is largest number",b);
        }
        else{
            printf("c = %d is largest number",c);
        }
    }
}




int main(){
    int a,b,c;
    printf("\n Enter value a ==>");
    scanf("%d",&a);
    printf("\n Enter value b ==>");
    scanf("%d",&b);
    printf("\n Enter value c ==>");
    scanf("%d",&c);

    max(a,b,c);
}
