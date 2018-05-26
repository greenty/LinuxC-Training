/* send.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>				/*包含相关函数头文件 */
#include <signal.h>

int main(int argc, char **argv)
{
  int state;
  pid_t res;
  union sigval sign;
  if(argc != 2) 				/* 检查命令行参数个数是否正确，这里需要输入接收进程的标识符 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  res = atoi(argv[1]); 		/* 获取信号接收进程标识符 */
  sign.sival_int = getpid();		/* 获取当前进程标识符，之后作为附加信息发送出去 */
  state = sigqueue(res, SIGUSR1, sign); 			/* 发送信号 */
  if(state < 0)
    printf("发送错误。\n");
  else
    printf("发送完成。\n");
  return 0;
}
