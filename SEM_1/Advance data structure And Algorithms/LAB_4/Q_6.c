struct student{
    int rollno;
    char name[50];
    int marks;
};
int main(){
    struct student s[2];
    int i,j;
    for(i=0;i<2;i++){
        printf("Enter the roll number, name and marks of student %d-->",i+1);
        scanf("%d", &s[i].rollno);
        scanf(" %[^\n]", s[i].name);  
        scanf("%d", &s[i].marks);
    }
    for(i=0;i<2;i++){
        for(j=i+1;j<2;j++){
            if (s[i].marks = s[j].marks){
                printf("Details of students with same marks:\n");
                printf("Rollno: %d\nName: %s\n marks: %d\n",s[i].rollno,s[i].name,s[i].marks);
                printf("Rollno: %d\nName: %s\n marks: %d\n",s[j].rollno,s[j].name,s[j].marks);
            }
        }
    }
}