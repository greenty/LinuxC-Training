/* example14.c */
#include <stdio.h>
#include <stdarg.h>					/* 包含相关函数头文件 */
int sum(int num, ...)				/* 求和 */
{
  int v, i;
  int sum = 0;
  va_list vp;						/* 定义指向可变参数列表的指针 */
  va_start(vp, num);				/* 使指针指向参数列表中的第一个可选参数 */
  i = num;
  while(i > 0)
  {
    v = va_arg(vp, int);			/* 返回指针所指向的参数，并将其后移 */
    sum += v;
    i--;
  }
  va_end(vp);
  return sum;
}
int main()
{
  printf("%d\n", sum(2, 5, 6));		/* 输出计算结果 */
  printf("%d\n", sum(4, 8, 2, 3, 1));
  return 0;
}
