/* example15.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>					/* 包含相关函数头文件 */
#include <sys/shm.h>
#define SIZE 1024				/* 共享内存的大小 */

int main()
{
  int id;
  key_t x;
  x = ftok("/home/tom/C", 'a'); 		/* 生成共享内存的键值 */
  if(x < 0) 						/* 如果ftok函数调用失败，输出错误信息并退出*/
  {
    perror("生成共享内存失败");
    exit(1) ;
  }
  id = shmget(x, SIZE, IPC_CREAT | 0666); 		/* 创建一块共享内存 */
  if(id < 0)
  {
    perror("创建共享内存失败");			/* 如果共享内存创建失败，输出错误信息并退出 */
    exit(1) ;
  }
  else
  {
    printf("创建共享内存成功。\n");
  }
  return 0;
}

