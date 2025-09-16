//Find maximum element in an array
//#include<stdio.h>
int max(int a[],int n){
    int i,maxx = a[1];
    for(i=1;i<=n; i++){
        if(maxx < a[i]){
            maxx = a[i];
        }
    }
    return maxx;
}
int sort_max(int a[],int n){
    int i,j;
    for(i=1;i<=n; i++){
        for(j=1;j<=n;j++){
            if(a[i]<a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    return a[n];
}
int main(){
    int a[8],i,n=7,max1,max2;
    printf("\n Enter temperature in array..");
    for (i = 1;i<=n;i++){
        printf("\n a[%d]=",i);
        scanf("%d",&a[i]);
    }
    max1 = max(a,n);
    printf("\n Maximum temperature using simple linear scan is %d",max1);

    max2 = sort_max(a,n);
    printf("\n Maximum temperature using sorting is %d",max2);
}
