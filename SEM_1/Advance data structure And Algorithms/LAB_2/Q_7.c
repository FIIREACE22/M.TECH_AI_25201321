//Generte n natural number
void recursion(int n){
    if(n==0)
        return;
    else
        recursion(n-1);
        printf(" %d",n);
}

int main(){
    int i,n;
    printf("Enter a number..");
    scanf("%d",&n);
    for(i=1 ; i<=n;i++){
        printf("%d ",i);
    }
    recursion(n);

}