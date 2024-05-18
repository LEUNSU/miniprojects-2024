/*
  2. 연결리스트 자료구조로 도서관리 프로그램을 작성하시오.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
  char title[20];
  char author[20];
  char publisher[20];
  int price;
  int borrowed;
  struct book* next;
}book;

typedef struct{
  book *head;
}headNode;

book* head = NULL;
book* book_rent = NULL;

void menu()
{
  printf("====== 메뉴======\n");
  printf("|1. 도서등록|\n");
  printf("|2. 도서검색|\n");
  printf("|3. 도서삭제|\n");
  printf("|4. 도서출력|\n");
  printf("|5. 도서반납|\n");
  printf("|0. 종료|\n");
}

void book_add()
{
  book* newBook = (book*)malloc(sizeof(book)); // 동적메모리할당

  printf("제목: ");
  scanf("%s", newBook->title);
  printf("저자: ");
  scanf("%s", newBook->author);
  printf("출판사: ");
  scanf("%s", newBook->publisher);
  printf("가격: ");
  scanf("%d", &newBook->price);

  newBook->borrowed = 0; // 새로운 도서 대출되지 않았음
  newBook->next = NULL;

  // 연결리스트에 도서 추가
  if(head == NULL)  // 리스트가 비어있을때
  {
    head = newBook;
  }
  else  // 리스트가 이미 책을 포함하고 있을떄
  {
    book* curr = head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = newBook;
  }
}

void book_print()
{
  book* curr = head;

  while(curr != NULL){
    printf("제목: %s  ", curr->title);
    printf("저자: %s  ", curr->author);

    printf("출판사: %s  ", curr->publisher);
    printf("가격: %d\n", curr->price);
    curr = curr->next;  // 다음 노드로 이동
  }
}


void book_search(char* title)
{
  if(head == NULL){ // 리스트가 비어있을 때
    printf("검색할 도서가 없습니다.\n");
    return;
  }
  book* curr = head;
  int result = 0;

  while(curr != NULL){
    if(strcmp(curr->title, title) == 0){

      if(curr->borrowed == 1 && result ==0){
        printf("이미 대출된 도서입니다.\n");
        return;
      }
      else if(curr->borrowed ==0){
        printf("도서를 찾았습니다.\n");
        printf("제목: %s  ", curr->title);
        printf("저자: %s  ", curr->author);
        printf("출판사: %s  ", curr->publisher);
        printf("가격: %d\n", curr->price);
        result++;
        printf("도서를 대여하시겠습니까(1: 예, 0: 아니오): \n");

      int choice;
      scanf("%d", &choice);
      if(choice == 1){
        curr->borrowed = 1; // 대출상태
      }
      else{
        printf("대여를 취소합니다.\n");
      }
      }
    }
    curr = curr->next;
  }
  if(result == 0){
    printf("도서를 찾을 수 없습니다.\n");
  }
}

void book_return(char* title)
{
  book* curr = head; // 대여된 도서목록의 시작을 가리키는 포인터

  // 반납할 도서 대여목록에서 검색
  while(curr != NULL){
    if(strcmp(curr->title, title) == 0){
      if(curr->borrowed == 0){
        printf("반납된 도서입니다.\n");
        return;
      }
      curr->borrowed = 0;

      printf("도서를 반납합니다\n");
      return;
    }
    curr = curr->next; // 다음 도서로 이동
  }
  printf("도서를 찾을 수 없습니다.\n");
}

void book_delete(char* title)
{
  if(head == NULL){ // 리스트가 비어있을 때
    printf("삭제할 도서가 없습니다.\n");
    return;
  }

  book* curr = head;
  book* prev = NULL;

  // 첫 번째 노드일 때
  if(strcmp(curr->title, title) == 0){
    head = curr->next;
    free(curr);
    printf("도서가 삭제되었습니다.\n");
    return;
  }

  // 중간 또는 마지막 노드일 때
  while(curr != NULL && strcmp(curr->title, title) != 0){ // 현재 노드[>
    prev = curr; // 현재 노드를 이전 노드로 설정
    curr = curr->next; // 다음 노드로 이동
  }

  if(curr == NULL){
    printf("도서를 찾을 수 없습니다.\n");
    return;
  }

  // 삭제할 노드가 중간노드일 때
  prev->next = curr->next; // 이전 노드의 next를삭제할 노드의 다음 노드>
  free(curr); // 현재 노드 해제
  printf("도서가 삭제되었습니다.\n");
}

void main()
{
  int choice;
  char title[20];

  while(1)
  {
    menu();
    printf("메뉴를 선택하세요: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        book_add();
        break;
      case 2:
        printf("검색할 도서의 제목을 입력하세요: ");
        scanf("%s", title);
        book_search(title);
        break;
      case 3:
        printf("삭제할 도서의 제목을 입력하세요: ");
        scanf("%s", title);
        book_delete(title);
        break;
      case 4:
        book_print();
        break;
      case 5:
        printf("반납할 도서의 제목을 입력하세요: ");
        scanf("%s", title);
        book_return(title);
        break;
      case 0:
        printf("프로그램을 종료합니다\n");
        exit(0);
      default:
        printf("잘못된 입력입니다.\n");
    }
  }
}
