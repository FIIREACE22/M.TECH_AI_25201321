//#include<stdio.h>
int main(){
    int a[10] ={1,23,56,48,56,42,78,43,96,54},n,i,j,max=0,max2=0;
    for(i=0 ;i<10;i++){
        if(a[i]>max){
            max2=max;
            max=a[i];
            
        }
        else if(a[i]>max2 && a[i]<max){
            max2=a[i];
        }
    }
    printf("The largest number is %d",max2);
    return 0;
}
