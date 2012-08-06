#include "header_files.h"

/* 책을 추가하는 insert 함수 */
//BOOK_NODE *insert(char *book, char *author, char *publisher, char *price, BOOK_NODE *list)
BOOK_NODE *insert(BOOK_NODE *book_st, BOOK_NODE *list)
{
    BOOK_NODE *current = NULL;  /* 앞장 서는 연결 선 */
    BOOK_NODE *follow = NULL;   /* 뒤 따라가는 연결 선 */
    BOOK_NODE *newnode = NULL;  /* 새로운 NODE */

    current = list;             /* current = follow = list; */
    follow = list;

    /* 새로운 노드 생성 */
    newnode = (BOOK_NODE *)malloc(sizeof(BOOK_NODE)); /* 동적할당을 받아서 새로운 NODE인 newnode를 만든다.  */
    if(newnode == NULL)                                /* 동적할당 실패시, 에러 메세지를 출력 후 종료. */
    {
        printf("Failed to allocate memory.\n");
        return list;            /* 원래 받았던 주소는 그냥 돌려준다. */
    }
    *newnode = *book_st;          /* 새로운 노드에 입력 받았던 내용을 넣는다. */

    printf("Debugging :: [[%s]]\n", newnode -> book); /* 디버깅용 printf. 내용을 잘 받았는지 검사. */
      
    /* 삽입 위치로 이동 */
    while((current != NULL) && (current -> book < book_st -> book)) /* 처음이 아니고, 오름차순으로.  */
    {
        follow = current;       /* follow는 current의 NODE에, */
        current = current -> next; /* current는 한개 NODE 전진. */
    }
    
    /* 삽입 */
    newnode -> next = current;  /* newnode 의 next에 current를 연결. 첫 NODE일 경우 NULL이 next에 연결됨. */
    if(current == list)        /* current와 list가 같을 경우는, */
    {
        list = newnode;
    }
    else
    {
        follow -> next = newnode; /* 그 외 경우에는 앞 노드의 next에 연결 됨. */
    }


    return list;                /* 첫 번째 NODE를 가지고 있는 list를 return 한다. */
}

void *print_links(BOOK_NODE *linked_list)
{
    BOOK_NODE *temp;

    temp = linked_list;

    printf("=================================================\n");
    printf("\tBook\tAuthor\tPublisher\tPrice\tYear\n");
    printf("-------------------------------------------------\n");
    while(temp != NULL)
    {
        
        printf("%s\t", temp -> book);
        printf("%s\t", temp -> author);
        printf("%s\t", temp -> publisher);
        printf("%s\t", temp -> price);
        printf("%s\n", temp -> year);
        temp = temp -> next;
    }
    printf("=================================================\n");

    
    return;
}

