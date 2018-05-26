/* client2.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <errno.h>
#include <fcntl.h>
#define SIZE 256
int main(int argc, char **argv)
{
  int res;
  int num;
  char buf[SIZE];				/* 定义缓冲区 */
  if(argc != 2)						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  res = open(argv[1], O_RDONLY | O_NONBLOCK);		/* 以非阻塞方式打开命名管道 */
  if(res < 0) 						/* 如果管道打开失败，输出错误信息并退出 */
  {
    perror("管道打开失败");
    exit(1);
  }
  printf("客户端：\n");
  while(1)
  {
    num = read(res, buf, sizeof(buf)); 	/* 从命名管道中读取消息 */
    if(num == -1)					/* 查看消息读取失败是否是由于当前命名管道中没有数据 */
    {
      if(errno == EAGAIN)
      {
        printf("没有接收到数据。\n");
      }
    }
    else
    {
      printf("实际读取到的字节数： %d\n", num); 		/* 输出实际读取的字节数 */
      printf("接收到的信息： %s", buf);		/* 输出接收到的消息 */
      break; 						/* 接收到了消息，跳出while循环 */
    }
    sleep(1);
  }
  return 0;
}

