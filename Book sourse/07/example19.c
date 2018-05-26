/* example19.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>					/* 包含相关函数头文件 */
#define SIZE 100000
int main()
{
  time_t start;
  time_t stop;
  int i, j;
  int *p;
  double res;
  time(&start);						/* 获取循环运行前的时间 */
  for(i=0; i<90000; i++)
  {
    p = (int *)malloc(SIZE*sizeof(int)); 	/* 分配内存空间 */
    for(j=0; j<SIZE; j++)
    {
      *(p+j) = j;					/* 初始化 */
    }
    free(p); 						/* 释放内存空间 */
  }
  time(&stop); 					/* 获取循环运行后的时间 */
  res = difftime(stop, start);			/* 计算时间差 */
  printf("%f\n", res);
  return 0;
}
