//Define a structure Book with fields title, author, and price. Input details for n books and
//then display all books whose price is above a given value.
struct Book{
    char title[50];
    char author[50];
    float price;
};
int main(){
    struct Book b[5];
    int i,n;
    float value;
    printf("Enter the number of books-->");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the title, author and price of book %d-->",i+1);
        scanf("%s %s %f",b[i].title,b[i].author,&b[i].price);
    }
    printf("Enter the price value-->");
    scanf("%f",&value);
    printf("The details of the books with price above %.2f are-->\n",value);
    for(i=0;i<n;i++){
        if(b[i].price > value){
            printf("Title: %s\nAuthor: %s\nPrice: %.2f\n",b[i].title,b[i].author,b[i].price);
        }
    }   
}