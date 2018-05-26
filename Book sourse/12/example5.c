/* example5.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>							/* 包含相关函数头文件 */

void newthread() 								/* 定义新线程运行的函数 */
{
  int i,res;
  res = pthread_setcancelstate(					/* 设置线程的取消状态 */
        PTHREAD_CANCEL_ENABLE, NULL);
  if(res != 0)
  {
    printf("取消状态设置失败。");		/* 如果取消状态未设置成功，打印错误信息 */
    exit(1);
  }
  res = pthread_setcanceltype(					/* 设置线程的取消类型 */
        PTHREAD_CANCEL_DEFERRED, NULL);
  if(res != 0)
  {
    printf("取消状态设置失败。");	 	/* 如果取消类型未设置成功，打印错误信息 */
    exit(1);
  }

  for(i=0; i<3; i++)								/* 连续输出字符串，同时显示运行位置 */
  {
    printf("线程正在运行(%d)…\n",i);
    sleep(1);
  }
  pthread_exit(NULL);		/* 终止当前线程 */
}

int main()
{
  pthread_t pth; 								/* 定义线程的标识符 */
  int res;
  res = pthread_create(&pth, NULL, (void *)newthread, NULL); 		/* 创建新的线程 */
  if(res != 0)
  {
    printf("创建线程错误。\n");					/* 如果线程创建失败，打印错误信息 */
    exit(1);
  }
  sleep(2);
  printf("正在取消线程…\n");
  res = pthread_cancel(pth);						/* 取消新建线程 */
  if(res != 0)
  {
    printf("取消线程失败。\n");				/* 如果线程取消失败，打印错误信息 */
    exit(1);
  }
  return 0;
}

