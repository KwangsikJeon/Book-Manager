#ifndef __STRUCTURE_FILE_H__
#define __STRUCTURE_FILE_H__

#pragma pack(1)                 /* 구조체를 1바이트 단위로 채워 넣는다. */


typedef struct dbf_header       /* 데이터 파일의 헤더를 위한 버퍼 */
{
    int amount_of_book;         /* 총 입력된 파일의 권 수. */
    char magic_number[30];      /* Asterisk로 이루어진 총 30바이트의 공간 */
    /* 헤더 파일은 위에 명시된 것과 같이 총 34바이트를 차지하게 된다. */
} DBF_HEADER;

typedef struct booktype         /*  책의 기본 구조체 */
{
    char book[30];
    char author[15];
    char publisher[15];
    char price[15];
    char year[15];
    struct booktype *next;
} BOOK_NODE;


#endif // __STRUCTURE_FILE_H__
