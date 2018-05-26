/* example1.c */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>				/* 包含相关函数头文件 */
int main()
{
  int x = 0x12345678; 				/* 以低位字节优先方式存储，即0x78 0x56 0x34 0x12 */
  int *p = &x;
  char h = *((char *)p); 				/* 将x的高位字节赋给h */
  printf("x = 0x%x\n", x);
  printf("h = 0x%x\n", h);
  int y = htonl(x); 					/* 转换为以高位字节优先方式，即0x12 0x34 0x56 0x78 */
  printf("y = 0x%x\n", y);
  return 0;
}
