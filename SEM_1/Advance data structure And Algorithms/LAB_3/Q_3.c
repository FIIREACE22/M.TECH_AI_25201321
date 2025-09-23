int main(){
    int arr[50],brr[5];
    int i,j,n,k;
    printf("Enter the 10 elements of the array-->");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the value of n-->");
    scanf("%d",&k);
    for(i=5;i<=5+k;i++){
        arr[i] = arr[i-5];
    }
    for(i=k+1;i<=5+k;i++){
        printf("%d ",arr[i]);
    }
}