/* example20.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含相关函数所在头文件 */
int main(int argc, char ** argv)
{
  int a;
  for (a=0; a<argc; a++)
  {
    printf("Argument %d is %s.\n", a, argv[a]);		/* 输出传入main函数的各个参数 */
  }
  return 0;
}
