/*Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.*/
int main(){
    int nums[100],n,i,j,flag=0;
    printf("Enter the number of elements in the array-->");
    scanf("%d",&n);
    printf("Enter the elements of the array-->");
    for(i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(nums[i] == nums[j]){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
}