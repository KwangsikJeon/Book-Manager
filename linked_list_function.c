#include <stdio.h>
#include <stdlib.h>
#include "linked_list_function.h"

/* 책을 추가하는 insert 함수 */
//BOOK_NODE *insert(char *book, char *author, char *publisher, char *price, BOOK_NODE *list)
BOOK_NODE *insert(char book, BOOK_NODE *list)
{
    BOOK_NODE *current = NULL;
    BOOK_NODE *follow = NULL;
    BOOK_NODE *newnode = NULL;

    current = list;             /* current = follow = list; */
    follow = list;

    /* 새로운 노드 생성 */
    newnode = (BOOK_NODE *)malloc(sizeof(BOOK_NODE));
    if(newnode = NULL)
    {
        printf("Failed to allocate memory.\n");
        return list;
    }
    newnode -> book[0] = 'a';

    /* 삽입 위치로 이동 */
    while((current != NULL) && (current -> book < book))
    {
        follow = current;
        current = current -> next;
    }
    
    /* 삽입 */
    newnode -> next = current;
    if(current == list)
    {
        list = newnode;
    }
    else
    {
        follow -> next = newnode;
    }

    return list;
}

