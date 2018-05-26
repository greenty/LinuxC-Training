/* example16.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>					/* 包含相关函数头文件 */
#include <sys/shm.h>
#define SIZE 1024				/* 共享内存的大小 */
#define TIMER 2

int main(int argc, char **argv)
{
  int id;
  key_t x;
  pid_t res;
  int psm;
  struct shmid_ds dsbuf;
  if(argc != 2) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  x = ftok("/home/tom/C", 'a'); 		/* 生成共享内存的键值 */
  if(x < 0) 						/* 如果ftok函数调用失败，输出错误信息并退出*/
  {
    perror("生存共享内存错误");
    exit(1) ;
  }
  id = shmget(x, SIZE, IPC_CREAT | 0666); 		/* 创建一块共享内存 */
  if(id < 0) 					/* 如果共享内存创建失败，输出错误信息并退出 */
  {
    perror("创建共享内存错误");
    exit(1) ;
  }
  res = fork();						/* 创建子进程 */
  if(res<0) 						/* 如果进程创建失败，输出错误信息并退出 */
  {
    perror("创建子进程错误\n");
    exit(1);
  }
  if(res==0) 						/* 子进程，向共享内存中写入数据 */
  {
    printf("子进程：\n");
    printf("PID : %d\n", getpid());		/* 输出子进程的标志符 */
    psm = (int)shmat(id, NULL, 0); 		/* 将共享内存映射到进程的地址空间中 */
    if(psm == -1) 					/* 如果映射失败，输出错误信息并退出 */
    {
      perror("映射失败\n");
      exit(1);
    }
    else							/* 共享内存映射成功 */
    {
      strcpy((char *)psm, argv[1]); 		/* 向共享内存中写入数据，这里传入为命令行参数 */
      printf("发送消息： %s\n", (char *)psm);
      if((shmdt((void *)psm)) < 0) 		/* 使共享内存脱离进程的地址空间 */
        perror("脱离进程失败\n");
      sleep(TIMER);
    }
  }
  else							/* 父进程，从共享内存中读取数据 */
  {
    sleep(TIMER);
    printf("父进程：\n");
    printf("PID : %d\n", getpid());				/* 输出父进程的标志符 */
    if((shmctl(id, IPC_STAT, &dsbuf)) < 0) 	/* 获取共享内存的状态信息 */
    {
      perror("获取共享内存状态错误\n");
      exit(1);
    }
    else 									/* 共享内存的状态信息获取成功 */
    {
      printf("共享内存信息：\n");
      printf("\t共享内存进程标识符： %d\n", dsbuf.shm_cpid); 		/* 输出创建共享内存进程的标识符 */
      printf("\t共享内存大小： %d\n",dsbuf.shm_segsz); 		/* 输出共享内存的大小 */
      printf("\t上一次操作共享内存进程标识符：%d\n",dsbuf.shm_lpid); 	/* 输出上一次操作共享内存进程的标识符 */
      psm = (int)shmat(id, NULL, 0); 					/* 将共享内存映射到进程的地址空间中 */
      if(psm == -1) 									/* 如果映射失败，输出错误信息并退出 */
      {
        perror("共享内存映射错误\n");
        exit(1);
      }
      else										/* 共享内存映射成功 */
      {
        printf("读取数据： %s\n", (char *)psm);		/* 从共享内存中读取数据 */
        if(shmdt((void *)psm) < 0) 						/* 使共享内存脱离进程的地址空间 */
          perror("脱离进程错误\n");
      }
    }
    if(shmctl(id, IPC_RMID, NULL) < 0) 				/* 删除前面创建的共享内存 */
    {
      perror("删除共享内存错误\n");
      exit(1);
    }
  }
  return 0;
}
