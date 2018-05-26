/* exampe15.c */
#include <stdlib.h>
#include <stdio.h>
int max(int, int); 				/* 函数声明 */
int main(void)
{
  int x,y,m;
  x=3;
  y=4;
  m=max(x,y); 				/* 函数调用 */
  printf("max :%d\n",m); 			/* 输出结果 */
  return 0;
}
int max(int i, int j) 				/* 函数定义，求两个数的最大值 */
{
  int t;
  t=(i>j)?i:j; 					/* 问号表达式 */
  return t ;
}
