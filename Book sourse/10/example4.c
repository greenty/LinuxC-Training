/* example4.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
int main()
{
  pid_t pid;
  pid = fork();						/* 创建新的进程 */
  if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程失败。\n");
    exit(1);
  }
  if(pid==0)						/* 子进程 */
    printf("这是一个子进程。\n");
  else								/* 父进程 */
    printf("这是一个父进程。\n");
  return 0;
}
