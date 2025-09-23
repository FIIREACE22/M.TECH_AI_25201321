int main(){
    int arr[10];
    int i,j,n,k;
    printf("Enter the 10 elements of the array-->");
    for(i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the value of n-->");
    scanf("%d",&n);
    for(i=0;i<10;i++){
        int sum=0;
        for(j=i;j<10;j++){
            sum = sum + arr[j];
            if(sum==n){
                printf("The subarray with sum %d is from index %d to %d\n",n,i,j);
        }
    }
}
}