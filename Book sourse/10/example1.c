/* example6.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含相关函数头文件 */
int main()
{
  system("ps -o pid,ppid,comm ");	/* 调用system函数 */
  return 0;
}
