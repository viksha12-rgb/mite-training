#include<stdio.h>
struct Fiction_t
{
    char title[200];
    char author[120];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t
{
  char title[200];
  char subject[500];
  float price;
};  
typedef struct NonFiction_t NonFiction;

union BookType_t
{
    Fiction fiction;
    NonFiction nonFiction;
};
typedef struct BookType_t BookType;

struct Book_t
{
    int type;
    BookType booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookCount;

void addBooks();
void displayBooks();

int main()
{
   addBooks();
   displayBooks();
   return 0;
}
void addBooks()
{
    printf("Enter the number of books:");
    scanf("%d",&bookCount);
    for(int i=0;i<bookCount;i++)
    {
        printf("Tyoe of book(1_Fiction,2_Non fiction):");
        scanf("%d",&books[i].type);
        
        switch(books[i].type)
        {
            case 1:{
                printf("Enter Fiction Book Details(Title,Author,Price):");
                scanf("%s%s%f",books[i].booktype.fiction.title,books[i].booktype.fiction.author,books[i].booktype.fiction.price);
            }break;
            case 2:{
                printf("Enter Non Fiction Book Details(Title,Subject,Price):");
                scanf("%s%s%f",books[i].booktype.nonFiction.title,books[i].booktype.nonFiction.subject,books[i].booktype.nonFiction.price);
            }break;
        }
    }
}
void displayBooks()
{
  for(int i=0;i<bookCount;i++)
  {
     switch(books[i].type)
        {
            case 1:{
                printf("Fiction Book:%s,Author:%s,Price:%.2f\n",books[i].booktype.fiction.title,books[i].booktype.fiction.author,books[i].booktype.fiction.price);
  }break;
  case 2:{
      printf("Non Fiction Book:%s,Subject:%s,Price:%.2f\n",books[i].booktype.fiction.title,books[i].booktype.fiction.author,books[i].booktype.fiction.price);
}
}
}
}
