/* example5.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>					/* 包含相关函数头文件 */

void sign_handler(int sign) 				/* 信号处理函数 */
{
  switch(sign)
  {
    case 2: 						/* 处理SIGINT信号 */
      printf("处理SIGINT信号\n");
      break;
    case 3: 						/* 处理SIGQUIT信号 */
      printf("处理SIGQUIT信号\n");
      break;
    default:
      ;
  }
  return;
}

int main()
{
  printf("PID : %d\n", getpid());			/* 输出进程的标识符 */
  signal(SIGINT, sign_handler); 		/* 设置SIGINT信号的处理函数 */
  signal(SIGQUIT, sign_handler); 		/* 设置SIGQUIT信号的处理函数 */
  for(;;);							/* 无穷循环 */
  return 0;
}
