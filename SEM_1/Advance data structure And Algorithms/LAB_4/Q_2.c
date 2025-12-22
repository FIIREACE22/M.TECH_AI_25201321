//#include<stdio.h>
//#include<string.h>
struct employee{
    int id;
    char name[20];
    float salary;  
    char department[20];
};
int main(){
    struct employee e[2];
    int i,j;
    for(i=0;i<2;i++){
        printf("Enter the id, name, salary and department of employee %d-->",i+1);
        scanf("%d %s %f %s",&e[i].id,e[i].name,&e[i].salary,e[i].department);
    }

    for(i=0;i<2;i++){
        printf("ID: %d\nName: %s\nSalary: %.2f\nDepartment: %s\n",e[i].id,e[i].name,e[i].salary,e[i].department);
    }   

}