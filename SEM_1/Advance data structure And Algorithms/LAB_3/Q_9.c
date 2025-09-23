/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".*/
int main(){
    int n,i,j,min_len;
    char strs[100][100],prefix[100];
    printf("Enter the number of strings-->");
    scanf("%d",&n);
    printf("Enter the strings-->\n");
    for(i=0;i<n;i++){
        scanf("%s",strs[i]);
    }
    min_len = strlen(strs[0]);
    for(i=1;i<n;i++){
        if(strlen(strs[i]) < min_len){
            min_len = strlen(strs[i]);
        }
    }
    for(i=0;i<min_len;i++){
        for(j=1;j<n;j++){
            if(strs[j][i] != strs[0][i]){
                prefix[i] = '\0';
                printf("The longest common prefix is: %s\n",prefix);
                return 0;
            }
        }
        prefix[i] = strs[0][i];
    }
    prefix[min_len] = '\0';
    printf("The longest common prefix is: %s\n",prefix);
    return 0;
}