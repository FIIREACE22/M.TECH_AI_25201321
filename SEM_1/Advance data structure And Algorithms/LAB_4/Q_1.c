//#include<stdio.h>
struct comp{
    int real;
    int imagenari;
};
int main(){
    struct comp num1 , num2;
    printf("Enter complex number for num2 and num2..\n");
    printf("num1--> \n");
    scanf("%d",&num1.real);
    scanf("%d",&num1.imagenari);
    printf("num2--> \n");
    scanf("%d",&num2.real);
    scanf("%d",&num2.imagenari);

    printf("num1 = %d + %di \n",num1.real,num1.imagenari);
    printf("num2 = %d + %di \n",num2.real,num2.imagenari);

    printf("After swapiing... \n");
    int t1 = num1.real;
    num1.real = num2.real;
    num2.real = t1;

    int t2 = num1.imagenari;
    num1.imagenari = num2.imagenari;
    num2.imagenari = t2;

    printf("num1 = %d + %di \n",num1.real,num1.imagenari);
    printf("num2 = %d + %di \n",num2.real,num2.imagenari);

}