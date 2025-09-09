#include<stdio.h>

int main(){
    int a[5]={1,6,87,58,65};
    int n,max,i;
    max=a[0];
    for(i=0 ; i<5 ;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    printf("max ==> %d",max);

}
