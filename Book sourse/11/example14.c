/* example14.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>					/* 包含相关函数头文件 */
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

int main()
{
  int id;
  pid_t flg;
  key_t x;
  struct sembuf lock = {0, -1, SEM_UNDO};
  struct sembuf unlock = {0, 1, SEM_UNDO | IPC_NOWAIT};
  int i, res, sta;
  x = ftok("/home/tom/C", 'b');			/* 生成信号量的键值 */
  id = semget(x, 1, IPC_CREAT | 0666);			/* 创建一个信号量集 */
  if(id < 0) 						/* 如果信号量创建失败，输出错误信息并退出 */
  {
    perror("信号量创建失败");
    exit(1) ;
  }
  res = semctl(id, 0, SETVAL, 1);		/* 将信号量的值设为1 */
  if(res == -1) 							/* 如果操作失败，输出错误信息并退出 */
  {
    perror("信号量设置失败");
    exit(1);
  }
  flg = fork();							/* 创建子进程 */
  if(flg < 0) 							/* 如果进程创建失败，输出错误信息并退出 */
  {
    perror("创建子进程失败");
    exit(1);
  }
  if(flg == 0) 										/* 子进程 */
  {
    for(i=0; i<3; i++)
    {
      sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0)))); 		/* 休眠0~3秒 */
      res = semop(id, &lock, 1);						/* 申请访问共享资源 */
      if(res == -1)
      {
        perror("lock error");
        exit(1);
      }
      printf("子进程访问共享资源。\n");			/* 开始访问共享资源 */
      sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
      printf("访问完成。\n");
      res = semop(id, &unlock, 1); 					/* 共享资源访问完毕 */
      if(res == -1)
      {
        perror("解锁失败");
        exit(1);
      }
    }
  }
  else											/* 父进程 */
  {
    for(i=0; i<3 ;i++)
    {
      sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
      res = semop(id, &lock, 1); 					/* 申请访问共享资源 */
      if(res == -1)
      {
        perror("锁定失败");
        exit(1);
      }
      printf("父进程访问共享资源。\n");		/* 开始访问共享资源 */
      sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
      printf("访问完成。\n");
      res = semop(id, &unlock, 1); 					/* 共享资源访问完毕 */
      if(res == -1)
      {
        perror("解锁失败");
        exit(1);
      }
    }
    if(flg != wait(&sta)) 				/* 等待子进程结束 */
    {
      printf("等待子进程结束失败。");
      exit(1);
    }
    res = semctl(id, 0, IPC_RMID, 0); 	/* 删除信号量 */
    if(res == -1) 						/* 如果信号量删除失败，输出错误信息并退出 */
    {
      perror("信号量删除失败");
      exit(1);
    }
  }
  return 0;
}
