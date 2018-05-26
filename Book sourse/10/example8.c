/* example8.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int sta;
  char *arrArg[] = {"test", "A", "B", "C", NULL};
  char *arrEnv[] = {"env1=150", "env2=tom", NULL};
  pid = vfork();						/* 使用vfork函数创建新进程 */
  if(pid<0)							/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建新进程失败。\n");
    exit(1);
  }
  if(pid==0) 						/* 新进程 */
  {
    execve ("./exe/test", arrArg, arrEnv);/* 调用上面的可执行文件test，输出各命令行参数和新的环境变量 */
  }
  else							/* 父进程 */
  {
    if(pid != wait(&sta)) 				/* 等待进程结束 */
    {
      printf("等待子进程失败。\n");
      exit(1);
    }
  }
  return 0;
}

