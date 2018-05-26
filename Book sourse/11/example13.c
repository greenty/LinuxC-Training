/* example13.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>				/* 包含相关函数头文件 */
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
  int id;
  key_t x;
  x = ftok("/home/tom/C", 'a'); 		/* 生成信号量的键值 */
  if(x < 0) 						/* 如果ftok函数调用失败，输出错误信息并退出*/
  {
    perror("生成键值错误");
    exit(1) ;
  }
  id = semget(x, 1, IPC_CREAT | 0666); 		/* 创建一块信号量集 */
  if(id < 0)
  {
    perror("创建信号量集错误");			/* 如果信号量创建失败，输出错误信息并退出 */
    exit(1) ;
  }
  printf("创建信号量集成功。\n");
  return 0;
}
