/* example4.c */
#include <stdlib.h>
#include <stdio.h>
int main()
{
  int m;							/* 定义一个int型变量m */
  int *pm;							/* 定义一个指针变量pm，用于存放int型变量的指针 */
  pm=&m;							/* 将变量m的指针赋给指针变量pm */
  m=1;
  printf("m = %d,*pm = %d\n",m, *pm);
  *pm=2;
  printf("m = %d,*pm = %d\n ",m, *pm);
  return 0;
}
