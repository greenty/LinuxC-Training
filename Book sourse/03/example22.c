/* exampe22.c */
#include <stdlib.h>
#include <stdio.h>
void fun(int);						/* 函数声明 */
int main()
{
  int i = 1;
  fun(i); 							/* 函数调用 */
  return 0;
}
void fun(int j) 						/* 函数定义 */
{
  if(j > 5)
  {
    printf("Done!\n");
    return;						/* 如果没有该语句，程序将进入死循环 */
  }
  printf("%d\n", j);
  fun(++j); 						/* 函数递归 */
  return;
}
