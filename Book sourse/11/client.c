/* client.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <errno.h>
#include <fcntl.h>
#define SIZE 256
int main(int argc, char **argv)
{
  int res;
  char buf[SIZE]; 				/* 定义缓冲区 */
  if(argc != 2) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  res = open(argv[1], O_RDONLY);		/* 打开命名管道，默认为阻塞方式 */
  if(res < 0)						/* 如果管道打开失败，输出错误信息并退出 */
  {
    perror("管道打开错误");
    exit(1);
  }
  printf("客户端：\n");
  read(res, buf, sizeof(buf)); 			/* 从命名管道中读取消息 */
  printf("接收到的信息： %s", buf);		/* 输出接收到的消息 */
  return 0;
}
