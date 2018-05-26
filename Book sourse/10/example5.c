/* example5.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/wait.h>				
int main()
{
  pid_t pid;
  int sta, i = -1;
  pid = fork();						/* 创建新的进程 */
  if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程失败。\n");
    exit(1);
  }
  if(pid==0) 						/* 子进程 */
  {
    printf("这是一个子进程。\n");
  }
  else								/* 父进程 */
  {
    sleep(1);
    printf("这是一个父进程。\n");
    printf("等待子进程... \n");
    if(pid != wait(&sta)) 		/* 等待子进程结束 */
    {
      printf("等待子进程错误。\n");
      exit(1);
    }
    if(WIFEXITED(sta))			/* 判断子进程是否为正常结束 */
    {
      i = WEXITSTATUS(sta);		/* 返回状态值 */
    }
    printf("子进程 pid = %d\n", pid);		/* 输出子进程标识符 */
    printf("exit status = %d\n", i); 		/* 输出子进程结束状态值 */
  }
  return 0;
}
