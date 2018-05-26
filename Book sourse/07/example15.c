/* example15.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含函数所在头文件 */
#define SIZE 5
int main()
{
  int *p;
  int i, tol;
  p = (int *)malloc(SIZE*sizeof(int));		/* 分配内存空间 */
  if(p == NULL) 					/* 如果内存空间分配失败，输出错误信息 */
  {
    printf("malloc error\n");
  }
  else
  {
    tol = 0;						/* 清零 */
    for(i=0; i<SIZE; i++)
    {
      *(p+i) = i;					/* 对内存单元的引用*(p+i)等价于p[i] */
      tol += p[i];					/* 累加 */
    }
    free(p); 						/* 释放内存空间 */
  }
  printf("tol = %d\n", tol);
  return 0;
}
