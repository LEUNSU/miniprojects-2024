/*
  1. 아이디와 비밀번호 입력하여 맞으면 본인의 정보가 저장된 파일을 open한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  char my_id[20] = "abcd";
  char my_password[20] = "efgh";
  char id[20];
  char password[20];

/*
  char name[20] = "LEEEUNSU";
  int age = 26;

  FILE* fp;
  fp = fopen("myinfo.txt", "w");
  if(fp == NULL)
  {
    fprintf(stderr, "Error");
    exit(1);
  }
  fprintf(fp, "%s", name);
  fprintf(fp, "%d", age);
  printf("%s", name);
  printf("\n");
  printf("%d", age);
  printf("\n");
  fclose(fp);
*/

  while(1)
  {
    printf("ID : ");
    scanf("%s",id);
    printf("Password: ");
    scanf("%s", password);

    if(strcmp(my_id, id) == 0 && strcmp(my_password, password) == 0)
    {
      printf("로그인성공\n");

      FILE* fp;
      char buf[1024];
      fp = fopen("myinfo.txt", "r");
      if(fp == NULL) {
        fprintf(stderr, "ERROR");
        exit(1);
      }
      fscanf(fp,"%s", buf);
      printf("%s", buf);
      fclose(fp);
      printf("\n");

      break;
    }

    else
    {
      printf("일치하지 않습니다\n");
    }
  }
}


