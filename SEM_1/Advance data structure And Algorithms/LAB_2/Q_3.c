//Reverse the string
//#include<stdio.h>
void ReverseWithNewArray(const char str[],char reversed[]){
    int n = strlen(str);
    for (int i=0 ; i<n ;i++){
        reversed[i] = str[n-i-1];
    }
    reversed[n] = '\0';
    printf("\nreverse String --> %s \n\n",reversed);
}
void reverseInPlace(char str[]){
    int n = strlen(str);
    for(int i=0 ; i<n/2 ; i++){
        char t = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = t;
    }
    printf("\nreverse String in place --> %s \n\n",str);
}
int main(){
    char uname[] = "HelloWorld";
    char reversed[100];

    ReverseWithNewArray(uname, reversed);
    reverseInPlace(uname);

}

