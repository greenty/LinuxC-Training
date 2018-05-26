/* example9.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>					/* 包含相关函数头文件 */
pthread_mutex_t mutex;					/* 定义互斥量 */
pthread_cond_t cond;					/* 定义条件变量 */
int j;									/* 定义全局变量 */

void producer(void)			/* 定义生产者线程运行的函数，其功能是对全局变量x进行递增操作 */
{
  while(1)
  {
    pthread_mutex_lock(&mutex);		/* 对互斥量进行加锁操作 */
    int i;
    for(i=0;i<3-j;i++)						/* 当x的值小于3时，进行生产，即对j进行递增操作 */
    {
      j++;
      printf("生产：j=%d \n",j);
      sleep(1);
    }
    if(j>=3)							/* 当j的值等于3时，通知消费者 */
    {
      pthread_cond_signal(&cond);		/* 激活等待的消费者线程 */
      printf("激活完成。\n");
    }
    pthread_mutex_unlock(&mutex);		/* 对互斥量进行解锁操作 */
    sleep(1);
  }
  pthread_exit(NULL);					/* 终止当前线程 */
}

void consumer(void)			/* 定义消费者线程运行的函数，其功能是对全局变量j进行递减操作 */
{
  while(1)
  {
    pthread_mutex_lock(&mutex);		/* 对互斥量进行加锁操作 */
    while(j<3)
    {
      pthread_cond_wait(&cond,&mutex);	/*阻塞消费者线程*/
      printf("开始消费。\n");
    }
    while(j>0)							/* 当j的值大于0时，进行消费，即对j进行递减操作 */
    {
      j--;
      printf("消费：j=%d \n",j);
      sleep(1);
    }
    pthread_mutex_unlock(&mutex);		/* 对互斥量进行解锁操作 */
  }
  pthread_exit(NULL);					/* 终止当前线程 */
}

int main(void)
{
  pthread_t pth1,pth2;						/* 定义线程的标识符 */
  int res;
  res = pthread_mutex_init(&mutex, NULL);	/* 对互斥量进行初始化 */
  if(res != 0)
  {
    printf ("互斥量初始化失败。\n");
    exit (1);
  }
  res = pthread_cond_init(&cond, NULL);	/* 对条件变量进行初始化 */
  if(res != 0)
  {
    printf ("条件变量初始化失败。\n");
    exit (1);
  }
  res = pthread_create(&pth1, NULL, (void *)&producer, NULL);		/* 创建生产者线程 */
  if(res != 0)
  {
    printf ("生产者线程创建失败。\n");
    exit (1);
  }
  res = pthread_create(&pth2, NULL, (void *)&consumer, NULL);		/* 创建消费者线程 */
  if(res != 0)
  {
    printf ("消费者线程创建失败。\n");
    exit (1);
  }
  pthread_join(pth1,NULL);					/*线程合并 */
  pthread_join(pth2,NULL);
  return (0);
}

