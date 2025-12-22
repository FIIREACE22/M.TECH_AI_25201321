struct student{
    int rollno;
    char name[50];
    int marks;
};

int main(){
    struct student s[3];
    int i,j,max =-1;
    for(i=0;i<3;i++){
        printf("Enter the roll number, name and marks of student %d-->",i+1);
        scanf("%d", &s[i].rollno);
        scanf(" %[^\n]", s[i].name);  // reads full name (with spaces)
        scanf("%d", &s[i].marks);
    }

    for(i=0;i<3;i++){
        if (s[i].marks > max){
            max = s[i].marks;
            j =i;
        }
    }
    printf("Details of student with highest marks:\n");
    printf("Rollno: %d\nName: %s\n marks: %d\n",s[j].rollno,s[j].name,s[j].marks);
}