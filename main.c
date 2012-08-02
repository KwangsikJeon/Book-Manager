#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_io.h"            /* 파일 입·출력을 위한 함수를 포함 */
#include "linked_list_function.h"




/* 함수 원형부 시작 */
int menu_print(void);

void insert_book(void);
 
/* 함수 원형부 끝 */

int main()
{
    FILE *fp;

//    INIT_writing_header();      /* 헤더 파일을 초기화 */

    menu_print();
}


int menu_print()
{
    int choisen_menu_number;  /* 선택된 메뉴번호를 저장하는 변수 */

    while(1)
    {
        printf("\n");
        printf("1.  Insert\n");
        printf("2.  List\n");
        printf("3.  Quit\n\n");
        printf("Enter the number : ");

        scanf("%d", &choisen_menu_number);

        switch(choisen_menu_number)
        {
        case 1:                     /* 책을 추가한다. */
            insert_book();
            break;

        case 2:
            printf("You chose 2.\n");
            break;

        case 3:
            printf("Thanks for using. See you again.\n");
            exit(-1);

        default:                /* 사용자가 지정된 키 이외의 입력을 했을 경우 에러 메세지 출력 후 다시 메뉴를 출력. */
            printf("You enter the wrong number.\n");
        }
    }    
    return choisen_menu_number;
}

void insert_book(void)          /* 메뉴 1번인 Insert, 도서추가 부분을 구현 */
{
    BOOK_NODE books = {0, 0, 0, 0, 0, 0}; /* 구조체 멤버들을 NULL 로 초기화 한다. */
    BOOK_NODE *books_p = &books;
    
    printf("Enter the book's title : "); /* 책 제목을 입력 받는다. */
    scanf("%s", books_p -> book);

    printf("Enter the author's name : "); /* 저자 이름을 입력 받는다. */
    scanf("%s", books_p -> author);

    printf("Enter the publisher : "); /* 출판사 이름을 입력 받는다. */
    scanf("%s", books_p -> publisher);

    printf("Enter the price : "); /* 가격을 입력 받는다. */
    scanf("%s", books_p -> price);
        
    printf("Enter the published year : "); /* 출판년도를 입력 받는다. */
    scanf("%s", books_p -> year);
    
    printf("%s\n", books_p -> book); /* 입력받은 데이터를 확인 할 수 있게 한다. */
    printf("%s\n", books_p -> author);
    printf("%s\n", books_p -> publisher);
    printf("%s\n", books_p -> price);
    printf("%s\n", books_p -> year);

    writing_data_file(books_p); /* 입력받은 데이터를 데이터 파일에 쓴다. */
    //  strcpy(books.book, books_p -> book);
    
    
    
    return;
}
