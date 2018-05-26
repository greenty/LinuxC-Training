/* msgsend.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>					/* 包含相关函数头文件 */
#include <sys/ipc.h>
#include <sys/msg.h>
#define SIZE 128
struct msgbuf							/* 定义消息结构 */
{
  long msgtype; 							/* 消息的类型 */
  char msg[SIZE]; 					/* 消息的内容 */
};

int main()
{
  int res;
  key_t x;
  int flg;
  struct msgbuf buf;						/* 定义消息缓冲区 */
  x = ftok("/home/tom/C", 'a'); 			/* 生成消息队列的键值 */
  if(x < 0)
  {
    perror("生成消息列对错误");
    exit(1) ;
  }
  res = msgget(x, IPC_CREAT | 0666); 	/* 创建一个消息队列 */
  if(res < 0)
  {
    perror("创建消息列对错误");
    exit(1) ;
  }
  while(1)	
  {
    printf("输入信息： ");
    fgets(buf.msg, SIZE, stdin);		/* 从键盘输入消息的内容 */
    if(strncmp(buf.msg, "exit", 4) == 0) 		/* 如果从键盘输入exit，退出循环 */
      break;
    buf.msgtype = getpid();					/* 消息的类型，这里设置为当前进程的标识符 */
    flg = msgsnd(res, &buf, SIZE, 0); 	/* 向消息队列中写入一个消息 */
    if(flg < 0)
    {
      perror("写入消息错误");				/* 如果消息写入失败，输出错误信息 */
      exit(1) ;
    }
    else
    {
      printf("消息发送成功。\n");					/* 消息发送成功 */
    }
  } 
  return 0;
}
