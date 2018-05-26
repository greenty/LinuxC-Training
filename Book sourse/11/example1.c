/* example1.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <fcntl.h>
#include <sys/wait.h>
#define SIZE 256
int main()
{
  pid_t res;
  int sign[2]; 						/* 定义管道描述符 */
  int sta;
  char buf[SIZE] = "Linux C真棒!\n";
  if(pipe(sign) < 0) 					/* 创建匿名管道 */
  {
    printf("创建匿名管道错误。\n");
    exit(1);
  }
  res = fork();						/* 创建子进程 */
  if(res < 0) 						/* 如果子进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程错误。\n");
    exit(1);
  }
  if(res == 0) 						/* 子进程 */
  {
    close(sign[0]); 					/* 关闭管道的读端 */
    write(sign[1], buf, sizeof(buf)); 		/* 向管道中写入数据 */
  }
  else							/* 父进程 */
  {
    close(sign[1]); 					/* 关闭管道的写端 */
    read(sign[0], buf, sizeof(buf)); 		/* 从管道中读取数据 */
    printf("读取到的数据：\n%s", buf);
    if(res != wait(&sta)) 			/* 等待子进程结束 */
    {
      printf("等待子进程结束错误。\n");
      exit(1);
    }
  }
  return 0;
}
