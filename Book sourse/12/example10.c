/* example10.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>					/* 包含相关函数头文件 */
sem_t sem;							/* 定义信号量 */
char buffer[512];						/* 定义一个缓冲区，用于存放键盘输入的数据 */

void newthread(void)						/* 新线程运行的函数，主要实现字符个数的统计 */
{
  sem_wait(&sem);						/* 阻塞当前线程 */
  while(strncmp("exit",buffer,4)!=0)			/* 统计字符个数，直至输入的字符为“exit” */
  {
    printf("你输入了%d个字符。\n", strlen(buffer)-1);
    sem_wait(&sem);
  }
  pthread_exit(NULL);					/* 终止当前线程 */
}

int main()
{
  pthread_t pth;							/* 定义线程的标识符 */
  int res;
  res = sem_init(&sem,0,0);				/* 对信号量进行初始化 */
  if(res != 0)
  {
    printf ("信号量初始化失败。\n");
    exit (1);
  }
  res = pthread_create(&pth, NULL, (void *)&newthread, NULL);		/* 创建新的线程 */
  if(res != 0)
  {
    printf ("线程创建失败。\n");
    exit (1);
  }
  printf ("输入一些字符使用‘.’结束。\n");
  while(strncmp("exit",buffer,4)!=0)			/* 获取键盘输入的字符串，将其存入缓冲区 */
  {
    fgets(buffer,512,stdin);
    sem_post(&sem); 					/* 激活阻塞在信号量上的线程 */
  }
  pthread_join(pth, NULL);					/* 合并线程*/
  printf("线程合并。\n");
  sem_destroy(&sem);					/* 注销信号量 */
  return (0);
}

