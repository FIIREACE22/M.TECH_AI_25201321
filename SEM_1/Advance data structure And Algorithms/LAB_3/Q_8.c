/*Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use
the same element twice. */
int main(){
    int nums[100],n,target,i,j;
    printf("Enter the number of elements in the array-->");
    scanf("%d",&n);
    printf("Enter the elements of the array-->");
    for(i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("Enter the target value-->");
    scanf("%d",&target);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                printf("The indices of the two numbers that add up to %d are %d and %d\n",target,i,j);
            }
        }
    }
}