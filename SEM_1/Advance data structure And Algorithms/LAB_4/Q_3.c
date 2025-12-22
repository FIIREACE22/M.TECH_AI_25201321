struct student{
    int rollno;
    char name[50];
    struct DOB{
        int year,month,day;
    }d;
};

int main(){
    struct student s[2];
    int i,j;
    for(i=0;i<2;i++){
        printf("Enter the roll number, name and Date od birth in the format of yyyy mm dd of student %d-->",i+1);
        scanf("%d %s %d %d %d",&s[i].rollno,s[i].name,&s[i].d.year,&s[i].d.month,&s[i].d.day);
    }

    for(i=0;i<2;i++){
        printf("Rollno: %d\nName: %s\nDOB: %d-%d-%d\n",s[i].rollno,s[i].name,s[i].d.year,s[i].d.month,s[i].d.day);
    }
}