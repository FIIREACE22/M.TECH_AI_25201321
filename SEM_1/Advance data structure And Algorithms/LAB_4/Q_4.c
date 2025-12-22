//#include<stdio.h>
struct po{
    int i;
    struct po *next;
};
int main(){
    struct po node1 , node2;
    struct po *ptr;

    node1.i = 10;
    node1.next = 0;

    node2.i = 30;
    node2.next = 0;

    node1.next = &node2;

    ptr= &node1;
    while(ptr!= 0){
        printf("%d \n",ptr->i);
        ptr = ptr->next;
    }
}