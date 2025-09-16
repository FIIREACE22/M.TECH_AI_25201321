//Swap two numbers without using a temporary variable
#include<stdio.h>
void arithmetic_swap(int a , int b){
    a = a + b; 
    b = a - b;
    a = a - b; 
    printf("\n After swapping using arithmatic a = %d and b = %d",a,b);
}

void betwise_XOR_swap(int a , int b){
    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b; 
    printf("\n After swapping with betwise XOR a = %d and b = %d",a,b);
}
int main(){
    int a=5,b=10;
    printf("\n Before swapping a = %d and b = %d",a,b);
   arithmetic_swap(a,b);
   betwise_XOR_swap(a,b);
   return 0;
}