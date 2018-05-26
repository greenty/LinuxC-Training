/* example4.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>					/* 包含相关函数头文件 */

void newthread()						/* 定义新线程运行的函数 */
{
  int i;
  for(i=0; i<3; i++)						/* 连续输出字符串 */
  {
    printf("这是一个新线程。\n");
   // sleep(1);							/* 强行引起线程的切换 */
  }
  /* 终止当前线程，并返回一个指向字符串的指针 */
  pthread_exit("线程退出。");
}

int main()
{
  pthread_t pth; 						/* 定义线程的标识符 */
  int i,res;
  void *pth_result; 						/* 定义指针，用来存储线程的返回值 */
  res=pthread_create(&pth,NULL,(void *)newthread, NULL); 			/* 创建新的线程 */
  if(res != 0)
  {
    printf("创建线程错。\n");			/* 如果线程创建失败，打印错误信息 */
    exit(1);
  }
  for(i=0; i<3; i++)						/* 连续输出字符串 */
  {
    printf("这是主线程。\n");
  //  sleep(1);
  }
  /* 主线程阻塞，等待新建线程返回，并将返回值存储在前面定义的pth_result之中 */
  pthread_join(pth,&pth_result);
  for(i=0; i<3; i++)						/* 连续输出字符串 */
  {
    printf("这是主线程。\n");
  //  sleep(1);
  }
  printf("线程返回：%s\n", (char *)pth_result); 		/* 输出线程返回的字符串 */
  return 0;
}

