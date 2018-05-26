/* exampe19.c */
#include <stdlib.h>
#include <stdio.h>
void func();					/* 函数声明 */
int main(void)
{
  printf("Fisrt call func():\n");
  func();						/* 第一次调用函数func */
  printf("Second call func():\n");
  func();						/* 第二次调用函数func */
  return 0;
}
void func()					/* 函数定义 */
{
  int m=0; 					/* 定义自动局部变量a */
  static n=0; 					/* 定义静态局部变量n */
  m++;
  n++;
  printf("m = %d\nn = %d\n",m,n);
}
