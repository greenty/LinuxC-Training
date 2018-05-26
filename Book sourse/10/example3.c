/* example10.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含对应函数相关头文件 */
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int sta;
  pid = fork();						/* 创建新的进程 */
  if(pid<0)							/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("fork error.\n");
    exit(1);
  }
  if(pid==0) 						/* 子进程 */
  {
    printf("Child Process:\n");
    printf("pid = %d\n", getpid());		/* 获取当前进程的标识符 */
    printf("ppid = %d\n", getppid());		/* 获取父进程的标识符 */
    printf("gid = %d\n", getpgrp());		/* 获取进程的组标识符 */
    exit(1);
  }
  else							/* 父进程 */
  {
    
    printf("Parent Process:\n");
    printf("pid = %d\n", getpid());		/* 获取当前进程的标识符 */
    printf("ppid = %d\n", getppid());		/* 获取父进程的标识符 */
    printf("gid = %d\n", getpgrp());		/* 获取进程的组标识符 */
    if(pid != wait(&sta)) 			/* 等待进程结束 */
    {
      printf("wait error.\n");
      exit(1);
    }
  }
  return 0;
}
