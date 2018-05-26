/* example2.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#define SIZE 256
int main(int argc, char **argv)
{
  pid_t res;
  FILE *fop;
  int sign[2]; 						/* 定义管道描述符 */
  int state;
  char buf[SIZE];				/* 定义缓冲区 */
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
    fop = fopen(argv[1], "r");			/* 打开源文件 */
    if(fop == NULL)					/* 如果源文件打开失败，输出错误信息并退出 */
    {
      perror("打开源文件失败：");
      exit(1);
    }
    while (fgets(buf, sizeof(buf), fop) != NULL)		/* 逐行读取源文件内容 */
    {
      close(sign[0]); 					/* 关闭管道的读端 */
      write(sign[1], buf, sizeof(buf)); 		/* 将源文件内容写入到管道中 */
    }
    fclose(fop);						/* 关闭源文件 */
    strcpy(buf, "`");					/* 设置特殊字符，以表示源文件内容传送完毕 */
    close(sign[0]);
    write(sign[1], buf, sizeof(buf));
  }
  else							/* 父进程 */
  {
    fop = fopen(argv[2], "w");			/* 打开目标文件 */
    if(fop == NULL)					/* 如果目标文件打开失败，输出错误信息并退出 */
    {
      perror("打开目标文件失败：");
      exit(1);
    }
    close(sign[1]); 					/* 关闭管道的写端 */
    read(sign[0], buf, sizeof(buf)); 		/* 从管道中读取数据 */
    while('`' != buf[0]) 				/* 测试是否读到特殊字符 */
    {
      fputs(buf, fop);					/* 逐行写入到目标文件之中 */
      close(sign[1]);
      read(sign[0], buf, sizeof(buf));
    }
    fclose(fop); 						/* 关闭目标文件 */
    if(res != wait(&state))			/* 等待子进程结束 */
    {
      printf("等待子进程结束错误。\n");
      exit(1);
    }
    printf("操作完成！\n");
  }
  return 0;
}
