/* msgreceive.c */
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
  char msgtext[SIZE]; 					/* 消息的内容 */
};

int main()
{
  int res;
  key_t key;
  int flg;
  struct msgbuf buf;						/* 定义消息缓冲区 */
  key = ftok("/home/tom/C", 'a'); 			/* 生成消息队列的键值 */
  if(key < 0)
  {
    perror("生成消息队列错误");
    exit(1) ;
  }
  res = msgget(key,  IPC_EXCL | 0666); 	/* 打开消息队列 */
  if(res < 0)
  {
    perror("打开消息队列错误");
    exit(1) ;
  }
  while(1)	
  {
    memset(&buf, 0, sizeof(buf));			/* 清空消息缓冲区 */
    flg = msgrcv(res, &buf, SIZE, 0, 0); 	/* 从消息队列中读取一个消息 */
    if(flg < 0)
    {
      perror("读取消息错误");				/* 如果消息读取失败，输出错误信息 */
      exit(1) ;
    }
    else
    {
      printf("接收到的信息：\n");
      /* 输出接收到的消息，包括消息的类型、长度、以及消息的内容 */
      printf("类型：%ld, 长度：%d, 内容：%s\n", buf.msgtype, res, buf.msgtext);
    }
  } 
  return 0;
}
