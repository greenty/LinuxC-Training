/* example7.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int sta;
  pid = vfork();					/* 使用vfork函数创建新进程 */
  if(pid<0)							/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf(" 创建新进程失败。\n");
    exit(1);
  }
  if(pid==0) 						/* 新进程 */
  {
    execlp("ps", "ps", "-o", "pid,ppid,comm", NULL);		/* 调用execlp函数 */
  }
  else								/* 父进程 */
  {
    if(pid != wait(&sta)) 		/* 等待进程结束 */
    {
      printf("等待子进程失败。\n");
      exit(1);
    }
    printf(" 操作完成！ \n");
  }
  return 0;
}

