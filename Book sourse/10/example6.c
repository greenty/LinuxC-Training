/* example6.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/wait.h>
int i = 1;
void child_process()				/* 子进程 */
{
  printf("子进程： %d, i = %d\n", getpid(), i);
  i++;
  printf("子进程： %d, i = %d\n", getpid(), i);
}
int main()
{
  pid_t pid;
  int sta;
  pid = fork();						/* 创建新的进程 */
  if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程失败。\n");
    exit(1);
  }
  if(pid==0) 						/* 子进程 */
  {
    child_process();
  }
  else								/* 父进程 */
  {
    sleep(1);
    printf("父进程： %d, i = %d\n", getpid(), i);
    if(pid != wait(&sta))			/* 等待子进程结束 */
    {
      printf("等待子进程失败。\n");
      exit(1);
    }
  }
  return 0;
}
