/* server.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 256
int main(int argc, char **argv)
{
  int state;
  int res;
  char buf[SIZE];				/* 定义缓冲区 */
  if(argc != 2)						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  state = mkfifo(argv[1], 0750); 		/* 创建命名管道 */
  if(state < 0){ 					/* 如果管道创建失败，输出错误信息并退出 */
    perror("管道创建失败");
    exit(1);
  }
  res = open(argv[1], O_WRONLY); 		/* 打开命名管道，默认为阻塞方式 */
  if(res < 0) 						/* 如果管道打开失败，输出错误信息并退出 */
  {
    perror("管道打开失败");
    exit(1);
  }
  printf("服务器：\n");
  printf("输入信息：");
  fgets(buf, sizeof(buf), stdin); 			/* 从键盘输入要发送的消息 */
  write(res, buf, sizeof(buf)); 			/* 将消息写入命名管道之中 */
  printf("信息已经发送。\n");
  unlink(argv[1]);					/* 删除命名管道 */
  return 0;
}
