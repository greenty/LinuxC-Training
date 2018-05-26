/* example8.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>					/* 包含相关函数头文件 */
pthread_mutex_t mutex;					/* 定义互斥量 */
int x;									/* 定义全局变量 */

void thread1(void)				/* 定义线程1运行的函数，其功能是对全局变量x进行逐减操作 */
{
  while(x>0)
  {
    pthread_mutex_lock(&mutex);		/* 对互斥量进行加锁操作 */
    printf("线程1运行中：x=%d \n",x);
    x--;
    pthread_mutex_unlock(&mutex);		/* 对互斥量进行解锁操作 */
    sleep(1);
  }
  pthread_exit(NULL);
}

void thread2(void)				/* 定义线程2运行的函数，功能与thread1相同 */
{
  while(x>0)
  {
    pthread_mutex_lock(&mutex);		/* 对互斥量进行加锁操作 */
    printf("线程2运行中：x=%d \n",x);
    x--;
    pthread_mutex_unlock(&mutex);		/* 对互斥量进行解锁操作 */
    sleep(1);
  }
  pthread_exit(NULL);
}

int main()
{
  pthread_t pth1,pth2;						/* 定义线程的标识符 */
  int res;
  res = pthread_mutex_init(&mutex,NULL);	/* 对互斥量进行初始化，这里使用默认的属性 */
  if(res != 0)
  {
    printf ("互斥量初始化失败。\n");		/* 如果初始化失败，打印错误信息 */
    exit (1);
  }
  x=5;								/* 对全局变量赋初值 */
  res = pthread_create(&pth1, NULL, (void *)&thread1, NULL);	/* 创建线程1 */
  if(res != 0)
  {
    printf ("线程1创建失败。\n");
    exit (1);
  }
  res = pthread_create(&pth2, NULL, (void *)&thread2, NULL);	/* 创建线程2 */
  if(res != 0)
  {
    printf ("线程2创建失败。\n");
    exit (1);
  }
  pthread_join(pth1, NULL);				/*线程合并 */
  pthread_join(pth2, NULL);
  return (0);
}

