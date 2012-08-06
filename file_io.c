#include "header_files.h"

void writing_data_file(BOOK_NODE *books)           /*  저 수준 파일 입출력을 통한 데이터 파일 생성 함수 */
{
    char turple = '|';            /* 터플 */
    
    int infd;
    char buffer[40];
    
//  infd = open("book.dbf", O_CREAT | O_RDWR | O_BINARY); /* DOS 용. */

    INIT_writing_header();      /* 헤더 삽입 함수 */
    
    infd = open("book.dbf", O_RDWR); /* 리눅스용 */
    if(infd < 0)
    {
        perror("Sorry, failed to open the file.");
        exit(-1);
    }

    read(infd, buffer, 34);            /* 헤더 데이터 바로 다음 위치인 35바이트에 위치 시킨다. */

    while(1)                    /* 도서목록을 파일에 쓰기 위한 루틴. */
    {
        write(infd, books, (sizeof(BOOK_NODE) - 4)); /* 버퍼에 있는 내용을 파일에 쓴다. */

        read(infd, buffer, +1);  /* 터플을 쓰기 위해 1바이트 앞으로 간다. */
        write(infd, &turple, 1); /* 미리 선언된 터플을 파일에 쓴다. */
        
        if(books -> next == NULL) /* 목록의 끝인지를 판단 */
        {
            break;              /* 끝이면 저장 끝 */
        }
        else
        {
            books = books -> next;
        }
    }
    close(infd);                /* 파일 속성을 시스템에 알리기 위해서 한 번 닫았다가 연다. */

}

void INIT_writing_header()      /* 새로 생성된 데이터 파일에 헤더정보를 쓴다. */
{
    DBF_HEADER header = {0, "******************************"}; /* 구조체 초기화 별은 30개*/

    int outfd;

    /* 쓰기전용으로 파일을 연다. */
/* //    outfd = open("book.dbf", O_WRONLY | O_BINATY); /\* 바이너리 형태의 쓰기 전용으로 파일을 연다. *\/ */

    outfd = open("book.dbf", O_CREAT | O_TRUNC | O_WRONLY); /* 바이너리 형태의 쓰기 전용으로 파일을 새로 만든다. */
    if(outfd < 0)                                  /* 파일열기를 실패했을땐 종료. */
    {
        printf("Failed to open the file for writing.\n");
        exit(-1);
    }

    /* 헤더 부분을 작성하기 위해 준비된 구조체에 정보입력. */
    write(outfd, &header, sizeof(header)); /* 버퍼에 있는 내용을 파일에 쓴다. */
    
    close(outfd);               /* 파일을 닫는다. */
}

