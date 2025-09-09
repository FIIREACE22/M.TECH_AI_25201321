/*Q20. Recursive Binary Search
Scenario: A library system searches for a book ID in a sorted array of IDs. Implement binary
search using recursion.*/
int binarysearch(int arr[] , int left ,int right , int target){
    int mid = (left + right)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target < arr[mid]){
        return binarysearch(arr ,left , mid-1 , target);
    }
    else if(target > arr[mid]){
        return binarysearch(arr ,mid+1 , right , target);
    }
    else
        return -1;
}

int main(){
    int book_id[6] = {1,12,46,78,125,136};
    int n = sizeof(book_id)/4;
    int target,location;
    printf("Enter the book id of the book you want to search ==> ");
    scanf("%d",&target);

    location = binarysearch(book_id,0,n-1,target);
    if (location !=-1)
        printf("location of book book id %d is %d position , %d Index..",target,location+1,location);
}
