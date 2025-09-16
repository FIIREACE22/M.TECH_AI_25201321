//check pelindrom number
#include<stdio.h>
#include<string.h>

int reverseNumber(int n) { 
    int rev = 0;
    //printf("**************");
    while (n != 0) {
        int digit = n % 10;   
        rev = rev * 10 + digit; 
        n /= 10;              
    }
   // printf("Reversed Number: %d\n", rev);
    return rev;
}

int main(){
    char num[20];
    int i,n,flag=1,number,revNumber;
    printf("Enter a number..");
    scanf("%s",num);
    n = strlen(num);
    for(i=0 ; i<n ; i++){
        if(num[i] != num[n-i-1]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        printf("\n%s is pelindrom number",num);
    }
    else
        printf("\n%s is not pelindrom number",num);

    
    printf("\nEnter a number..>");
    scanf("%d",&number);
    revNumber = reverseNumber(number);
    if(number == revNumber){
        printf("%d is pelindrom number",number);
    }
    else{
        printf("%d is not pelindrom number",number);
    }
    return 0;
}