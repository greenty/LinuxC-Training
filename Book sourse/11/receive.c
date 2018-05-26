/* receive.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <signal.h>

void sign_handler(int sign, siginfo_t *info, void *t)		/* 信号处理函数 */
{
  printf("接收到的信号： %d\n", sign); 			/* 输出接收到的信号值 */
  printf("接收到的信息： %d\n", info->si_int); 	/* 输出接收到的附加信息，这里为发送进程的标志符 */
  return;
}

int main()
{
  int state;
  pid_t res;
  struct sigaction act; 				/* 定义sigaction结构 */
  res = getpid();					/* 获取当前进程标识符 */
  act.sa_sigaction = sign_handler; 		/* 使用sa_sigaction来设定处理函数 */
  sigemptyset(&act.sa_mask); 		/* 清空信号集中的所有信号 */
  act.sa_flags = SA_SIGINFO; 		/* 设置SA_SIGINFO标志位 */
  state = sigaction(SIGUSR1, &act, NULL);		/* 设置SIGUSR1信号的处理函数 */
  if(state < 0)
  {
    printf("设置处理函数错误。\n");
  }
  printf("接收：\n");
  printf("PID : %d\n", res); 			/* 输出当前进程标识符 */
  for(;;);							/* 无穷循环 */
  return 0;
}
