/* example11.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>				/* 包含相关函数头文件 */
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char **argv)
{
  int x;
  int state;
  if(argc != 2) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  x = atoi(argv[1]);					/* 获取要删除的消息队列的标识符 */
  state = msgctl(x, IPC_RMID, NULL);			/* 删除指定的消息队列 */
  if(state < 0) 					/* 如果消息队列删除失败，输出错误信息并退出 */
  {
    perror("消息队列删除失败");
    exit(1);
  }
  printf("消息队列删除成功。\n");				/* 消息队列删除成功 */
  return 0;
}
