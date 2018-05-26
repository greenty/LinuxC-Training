/* example4.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
#define SIZE 128			/* 缓冲区长度 */
int main()
{
  char src[] = "Linux C is very good!";
  char des[SIZE]; 			/* 定义内存缓冲区 */
  strcpy(des, src); 						/* 字符串复制 */
  printf("%s\n", des);
  return 0;
}
