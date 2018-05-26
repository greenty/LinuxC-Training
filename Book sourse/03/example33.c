/* exampe13.c */
#include <stdio.h>
#define N 5				/* 学生总数，为了方便程序输出结果的显示，这里设为5 */
struct student				/* 定义一个结构体数组，存储全班学生的学号和成绩 */
{
  int id;					/* 学号 */
  int score; 				/* 成绩 */
} stu[N];
int main()
{
  struct student *pt, *p[N]; 	/* 定义指向结构体的指针pt和指向结构体的指针构成的指针数组p */
  int i, j, k, tol=0;			/* tol为全班的总成绩 */
  printf ("Please input ID and Score :\n"); 
  for(i=0; i<=N-1; i++)
  {
    scanf("%d%d", &stu[i].id, &stu[i].score);		/* 输入学生的学号和成绩 */
    p[i] = &stu[i];			/* 将指针数组p的第i个元素（指针）指向结构体数组的第i个元素 */
    tol += stu[i].score;		/* 累计学生的分数 */
  }
  for(i=0; i<=N-2; i++ ) 		/* 按成绩排序 */
  {
    k = i;					/* 在第i次循环中，将指向当前最高分数的指针在指针数组p中的下标 */
    for(j=i; j<=N-1; j++)
    {
      if(p[k]->score < p[j]->score)				/* 查找当前最高分数 */
      {
        k = j;				/* k中存放当前最高分数对应的指针在指针数组p中的下标 */
      }
    }
    if(k!=i)				/* 当k不等于i时，交换两个指向结构体的指针 */
    {
      pt = p[i];
      p[i] = p[k];
      p[k] = pt;
    }
  }
  printf("ID Score\n");
  printf("------------------\n");
  for (i=0; i<=N-1; i++)		/* 按排序顺序输出学号和成绩 */
  {
    printf("%d %d\n", (*p[i]).id, p[i]->score);
  }
  printf ("Average score = %d\n", tol/N);		/* 输出平均分数 */
  return 0;
}
