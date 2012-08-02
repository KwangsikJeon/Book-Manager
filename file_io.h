#ifndef __FILE_IO_H__
#define __FILE_IO_H__

typedef struct booktype
{
    char book[30];
    char author[15];
    char publisher[15];
    char price[15];
    char year[15];
    struct booktype *next;
} BOOK_NODE;

void writing_data_file(BOOK_NODE *);  /* 최초 파일을 생성할 때  */
void INIT_writing_header(void); /* 헤더 부분을 작성한다. */

#endif  // __FILE_IO_H__
