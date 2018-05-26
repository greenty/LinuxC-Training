/* example8.c */
#include <stdio.h>
#include <signal.h>				/* 包含相关函数头文件 */
#include <unistd.h>
int main()
{
  int x;
  alarm(1);						/* 设置定时器 */
  x=0;
  while(1)
  {
    printf("x = %d\n", x);			/* 输出i的值 */
    x++;							/* 递增 */
  }
  return 0;
}
