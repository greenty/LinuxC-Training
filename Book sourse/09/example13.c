/* example13.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含相关函数头文件 */
int main()
{
  int x;
  int tol = 0;
  while (scanf("%d", &x) == 1) 		/* 读入整数，赋给变量x */
  {
    tol += x;						/* 累加 */
    printf("\t%3d\n", tol); 		/* 输出结果 */
  }
  return 0;
}
