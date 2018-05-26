/* example14.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含函数所在头文件 */
#define SIZE 64
int main()
{
  double num=123.456789;
  char ch[SIZE]; 			/* 定义缓冲区 */
  gcvt(num, 8, ch); 					/* 将浮点数转换为字符串，显示8位 */
  printf("%s\n", ch);
  gcvt(num, 13, ch); 					/* 将浮点数转换为字符串，显示13位 */
  printf("%s\n", ch);
  return 0;
}

