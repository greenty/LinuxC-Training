/* example6.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>							/* 包含相关函数头文件 */
#include <signal.h>

void sign_handler(int sign, siginfo_t *info, void *t) 		/* 信号处理函数 */
{
  printf("处理信号： %d\n", sign);
  return;
}

int main()
{
  int state;
  struct sigaction act; 					/* 定义sigaction结构 */
  act.sa_sigaction = sign_handler;			/* 使用sa_sigaction来设定处理函数 */
  sigemptyset(&act.sa_mask);				/* 清空信号集中的所有信号，后面介绍该函数 */
  act.sa_flags = SA_SIGINFO;				/* 设置SA_SIGINFO标志位 */
  state = sigaction(SIGINT, &act, NULL); 	/* 设置SIGINT信号的处理函数 */
  if(state < 0)
  {
    printf("设置信号处理函数错误。\n");
  }
  for(;;);								/* 无穷循环 */
  return 0;
}
