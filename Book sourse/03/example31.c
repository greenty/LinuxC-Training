/* exampe31.c */
#include <stdlib.h>
#include <stdio.h>
#define LEN 20
struct student
{
  int id;					/* 学号 */
  char name[LEN];			/* 姓名 */
  char sex; 				/* 性别 */
  double score; 			/* 成绩 */
};
int main()
{
  struct student stu = {001, "Jim", 'M', 98};
  struct student *p;			/* 定义指向结构体的指针*/
  p = &stu;				/* 将结构体stu的地址赋给p */
  printf("ID\t Name\t Sex\t Score\n");
  /* 通过三种不同的方式来引用结构体成员*/
  printf("%d\t %s\t %c\t %.1f\n", stu.id, stu.name, stu.sex, stu.score);
  printf("%d\t %s\t %c\t %.1f\n", (*p).id, (*p).name, (*p).sex, (*p).score);
  printf("%d\t %s\t %c\t %.1f\n", p->id, p->name, p->sex, p->score);
  return 0;
}
