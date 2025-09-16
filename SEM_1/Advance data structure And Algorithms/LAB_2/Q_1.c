// SUm of elements in array with recursion and regression
//#include<stdio.h>
void iterative_sum(int a[] , int n){
    int i,sum=0;
    for (i=0 ; i<n ;i++){
        sum = sum+ a[i];
    }
    printf("\n Sum of all elements in array is %d",sum);
}
int recursive_sum(int a[],int n){
    if(n == 0){
        return 0;
    }
    else{
        return a[n-1] + recursive_sum(a,n-1);
    }
}
int main(){
    int a[7],i,n=7,sum;
    printf("\n Enter elements in array..");
    for (i = 0;i<n;i++){
        printf("\n a[%d]=",i );
        scanf("%d",&a[i]);
    }
    iterative_sum(a,n);
    sum = recursive_sum(a,n);
    printf("\n Sum of all elements in array is %d",sum);
}
