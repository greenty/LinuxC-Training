/* example12.c */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>					/* 包含相关函数头文件 */
#define FILESIZE 1024
int main()
{
  pid_t pid;
  int i;
  time_t now;
  pid = fork();						/* 创建新的进程 */
  if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    printf("创建子进程失败。\n");
    exit(1);
  }
  if(pid>0) 						/* 终止父进程，使子进程进入后台运行 */
  {
    exit(0);
  }
  setsid();							/* 创建一个新的会话 */
  for(i=0; i<FILESIZE; i++)			/* 关闭打开的文件描述符 */
    close(i);
  chdir("/");						/* 改变工作目录 */
  umask(0);						/* 重设文件权限掩码 */
  signal(SIGCHLD, SIG_IGN); 		/* 处理SIGCHLD信号 */
  syslog(LOG_USER|LOG_INFO, "Daemon test!\n");		/* 写入到/var/log/messages文件之中 */
  while(1)
  {
    time(&now); 					/* 获取当前时间 */
    syslog(LOG_USER|LOG_INFO, "Current time:\t%s\t\t\n", ctime(&now));
    sleep(1);
  }
}
