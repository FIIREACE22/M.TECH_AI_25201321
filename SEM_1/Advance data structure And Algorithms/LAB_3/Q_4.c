struct student{
    char name[20];
    int rollNumber;
    int marks;
};
int main(){
    struct student s[5];
    int i,j;
    for(i=0;i<5;i++){
        printf("Enter the name, roll number and marks of student %d-->",i+1);
        scanf("%s %d %d",s[i].name,&s[i].rollNumber,&s[i].marks);
    }
    int max = s[0].marks;
    for(i=0;i<5;i++){
        if(s[i].marks>max){
            max = s[i].marks;
        }
    }
    printf("The details of the student with highest marks are-->\n");
    for(i=0;i<5;i++){
        if(s[i].marks==max){
            printf("Name: %s\nRoll Number: %d\nMarks: %d\n",s[i].name,s[i].rollNumber,s[i].marks);
        }
    }
    return 0;
}