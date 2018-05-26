/* example6.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>					/* 包含相关函数头文件 */
int pthflag=0;							/* 定义一个全局变量，来标志线程是否已经终止 */
void newthread(void)						/* 定义新线程运行的函数 */
{
  printf("线程正在运行…\n");
  sleep(3);
  printf("线程已经存在。\n");
  pthflag = 1;							/* 线程终止前设置状态标志 */
  pthread_exit(NULL);
}
int main()
{
  pthread_t pth; 						/* 定义线程的标识符 */
  pthread_attr_t attr;						/* 定义线程的属性对象 */
  int res;
  res = pthread_attr_init(&attr);			/* 对线程的属性对象进行初始化 */
  if(res!=0) 							/* 如果初始化失败，输出错误信息 */
  {
    printf ("线程对象初始化失败。\n");
    exit (1);
  }
  /* 将线程设置为分离状态 */
  res=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if(res!=0){
    printf ("设置分离属性失败。\n");	/* 如果属性设置失败，打印错误信息 */
    exit (1);
  }
  res=pthread_create(&pth, &attr, (void *)newthread, NULL);		/* 创建新的线程 */
  if(res!=0){
    printf ("创建线程失败。\n");
    exit (1);
  }
  while(!pthflag)					/* 检测线程是否已经终止 */
  {
    printf("等待线程完成…\n");
    sleep(1);
  }
  printf("线程操作完成。\n");				/* 线程已经终止，输出信息 */
  return 0;
}

