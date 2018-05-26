/* example9.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
#define SIZE 64
int main()
{
  char ch1[SIZE] = "Linux C";
  char ch2[SIZE] = " is very good!";
  strcat(ch1, ch2);						/* 连接字符串 */
  printf("%s\n", ch1); 					/* 输出源字符串 */
  printf("%s\n", ch2); 					/* 输出目标字符串 */
  return 0;
}
