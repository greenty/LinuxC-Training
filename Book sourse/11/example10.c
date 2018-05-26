/* example10.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>				/* 包含相关函数头文件 */
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
  int msg;
  key_t x;
  x = ftok("/home/tom/C", 'a');	/* 生成消息队列的键值 */
  if(x < 0) 						/* 如果ftok函数调用失败，输出错误信息并退出*/
  {
    perror("生成消息队列错误");
    exit(1) ;
  }
  msg = msgget(x, IPC_CREAT | 0666);		/* 创建一个消息队列 */
  if(msg < 0)
  {
    perror("创建消息队列失败"); 			/* 如果消息队列创建失败，输出错误信息并退出 */
    exit(1) ;
  }
  else
  {
    printf("创建消息队列成功。\n");				/* 如果消息队列创建成功，输出Done! */
  }
  return 0;
}
