/* example9.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <signal.h>
#define TIMER 5

void sign_handler(int sig) 				/* 信号处理函数 */
{
  printf("接收到的信号：SIGINT\n");	/* 输出收到的信号 */
  return;
}

int main()
{
  sigset_t def;						/* 定义信号集 */
  sigemptyset(&def); 				/* 初始化信号集，清空所有信号 */
  sigaddset(&def, SIGINT); 			/* 将SIGINT信号添加到信号集中 */
  signal(SIGINT, sign_handler); 		/* 设置SIGINT信号的处理函数 */
  while(1)
  {
    sigprocmask(SIG_BLOCK, &def, NULL);		/* 阻塞信号 */
    printf("阻塞信号。\n");
    sleep(TIMER);
    sigprocmask(SIG_UNBLOCK, &def, NULL); 	/* 解除阻塞 */
    printf("解除信号阻塞。\n");
    sleep(TIMER);
  }
  return 0;
}
