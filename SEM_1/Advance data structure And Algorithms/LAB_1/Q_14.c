#include<stdio.h>

int main(){
    char a[50]={"HELLO World Harsh"};
    int i=0,c=0;

    while(i<50){
        if(a[i]=='a'|| a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='i'||a[i]=='I'||a[i]=='o'||a[i]=='O'||a[i]=='u'||a[i]=='U')
            {
                c++;
            }
        i++;
    }
    printf("no. of vowels ==> %d",c);
}
