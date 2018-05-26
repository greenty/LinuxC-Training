/* example9.c */
#include <stdlib.h>			/* 包含相关函数头文件 */
#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("Linux C\n");	
  printf("非常棒！");
  _exit(0);					/*调用函数终止进程*/
}
