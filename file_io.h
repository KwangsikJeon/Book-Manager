#ifndef __FILE_IO_H__
#define __FILE_IO_H__

void INIT_writing_header(void); /* 헤더 부분을 작성한다. */
void writing_data_file(BOOK_NODE *);  /* 최초 파일을 생성할 때  */
void loading_data_file(BOOK_NODE *);  /* 파일을 불러 들인다. */

#endif  // __FILE_IO_H__
