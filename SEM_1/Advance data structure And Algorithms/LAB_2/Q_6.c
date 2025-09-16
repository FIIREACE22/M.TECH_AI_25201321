int linear_search(int a[],int n,int x){
    int i;
    for(i = 0 ; i<n ; i++){
        if(x == a[i]){
            return i;
            break;
        }
    }
}
void sentinelSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;   
    int i = 0;

    while (arr[i] != key) {
        i++;
    }

    arr[n - 1] = last;  

    if (i < n - 1 || arr[n - 1] == key) {
        printf("\nElement found at index: %d\n", i);
    }
    else {
        printf("\nElement not found in the array\n");
    }  
}

int main(){
    int a[7],i,n=7,x,ans;
    printf("\n Enter elements in array..");
    for (i = 0;i<n;i++){
        printf("\n a[%d]=",i );
        scanf("%d",&a[i]);
    }
    printf("\nEnter the number you want to find in array..");
    scanf("%d",&x);
    ans = linear_search(a,n,x);
    printf("\n%d is in %d position",x,ans);

    sentinelSearch(a,n,x);
}