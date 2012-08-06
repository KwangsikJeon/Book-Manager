#include "header_files.h"

BOOK_NODE *main_list = NULL; /* 이 변수는 반드시 도서목록 연결 리스트의 시작을 가지고 있어야 한다. */

int menu_print()
{

    int choisen_menu_number;  /* 선택된 메뉴번호를 저장하는 변수 */

    while(1)                    /* 메뉴는 종료를 선택할 때까지 반복해서 출력된다. */
    {
        printf("1.  Insert\n");
        printf("2.  List\n");
        printf("3.  Save as a data file\n");
        printf("4.  Quit\n\n");
        printf("Enter the number : ");

        scanf("%d", &choisen_menu_number);

        switch(choisen_menu_number)
        {
        case 1:                     /* 책을 연속적으로 추가하는 기능을 기본으로 한다. */
            insert_book();
            break;

        case 2:
            print_list_books(); /* 입력된 도서목록을 출력하며 책 추가 기능과 삭제 기능이 있다. */
            break;

        case 3:
            writing_data_file(main_list);
            break;

        case 4:
            printf("Thanks for using. See you again.\n");
            exit(-1);
            

        default:                /* 사용자가 지정된 키 이외의 입력을 했을 경우 에러 메세지 출력 후 다시 메뉴를 출력. */
            printf("You enter the wrong number.\n");
        }
    }    
    return choisen_menu_number;
}

void insert_book()          /* 메뉴 1번인 Insert, 도서추가 부분을 구현 */
{

    BOOK_NODE books = {0, 0, 0, 0, 0, 0}; /* 구조체 멤버들을 NULL 로 초기화 한다.
                                           * 초기화는 {0, }; 와 같은 방법도 가능하다.*/

    printf("Enter the book's title : "); /* 책 제목을 입력 받는다. */
    scanf("%s", books.book);

    printf("Enter the author's name : "); /* 저자의 이름을 입력 받는다. */
    scanf("%s", books.author);

    printf("Enter the publisher's name : "); /* 발행처를 입력 받는다. */
    scanf("%s", books.publisher);

    printf("Enter the price of the book : "); /* 책의 가격을 입력 받는다. */
    scanf("%s", books.price);

    printf("Enter the year of publishing : "); /* 책의 발행 연도를 입력 받는다. */
    scanf("%s", books.year);
           
    main_list = insert(&books, main_list); /* 도서목록 연결 리스트에 추가한다. */

    writing_data_file(main_list); /* 입력받은 데이터를 데이터 파일에 쓴다. */
}

void print_list_books()         /* 메뉴 2번인 도서목록 출력을 구현. */
{
    print_links(main_list);
    return;
}

