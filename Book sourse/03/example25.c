/* exampe25.c */
#include <stdlib.h>
#include <stdio.h>
typedef void (*FunType)(int, int);		/* 定义函数指针类型FunType */
void add(int, int); 					/* 函数声明 */
void sub(int, int);
void fun(FunType, int, int);
int main()
{
  int x = 2;
  int y = 3;
  fun(add, x, y);				/* 将函数指针作为参数调用fun函数 */
  fun(sub, x, y);
  return 0;
}
void add(int a, int b)					/* 两数相加 */
{
  int result;
  result = a + b;
  printf("%d + %d = %d\n", a, b, result);
}
void sub(int a, int b) 					/* 两数相减 */
{
  int result;
  result = a - b;
  printf("%d - %d = %d\n", a, b, result);
}
void fun(FunType p, int a, int b) 		/* 函数的参数为函数指针 */
{
  (*p)(a, b);
}
