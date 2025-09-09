void swap(a,b){
    int t;
    t=a;
    a=b;
    b=t;

    printf("\n Values after swap are %d And %d",a,b);
}




int main(){
    int a,b;
    printf("\n Enter value a ==>");
    scanf("%d",&a);
    printf("\n Enter value b ==>");
    scanf("%d",&b);

    swap(a,b);
}
