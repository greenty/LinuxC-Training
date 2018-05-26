/* example11.c */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <signal.h>
#define FILESIZE 1024
int main()
{
  pid_t pid;
  FILE *fp; 						/* 定义文件指针 */
  int i;
  char *buf = "这是一个示例程序。\n";
  pid = fork();						/* 创建新的进程 */
  if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程失败。\n");
    exit(1);
  }
  if(pid>0)							/* 终止父进程，使子进程进入后台运行 */
  {
    exit(0);
  }
  setsid();							/* 创建一个新的会话 */
  for(i=0; i<FILESIZE; i++)			/* 关闭打开的文件描述符 */
    close(i);
  chdir("/tmp");						/* 改变工作目录 */
  umask(0);						/* 重设文件权限掩码 */
  signal(SIGCHLD, SIG_IGN);			/* 处理SIGCHLD信号 */
  while(1)
  {
    fp = fopen("/tmp/test", "a");			/* 打开文件 */
    if(fp == NULL)
    {
      perror("打开测试文件失败。 ");		/* 如果文件打开失败，输出错误信息 */
      exit(1);
    }
    fputs(buf, fp);					/* 向文件写入字符串 */
    fclose(fp);					 	/* 关闭文件 */
    sleep(1);
  }
}

