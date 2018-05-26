/* exampe24.c */
#include <stdlib.h>
#include <stdio.h>
void fun(int); 						/* 函数声明 */
int main()
{
  int x = 6;
  void (*p)(int);						/* 定义函数指针变量 */
  p = &fun;						/* 将fun函数的首地址赋给函数指针变量p */
  fun(x); 							/* 直接调用fun函数 */ 
  (*p)(x);							/* 通过函数指针变量p调用fun函数 */
  return 0;
}
void fun(int x)						/* 函数定义 */
{
  printf("%d\n", x);
}
