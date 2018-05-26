/* example3.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
int main()
{
  char ch[] = "Linux C is very good!";
  printf("%s\n", ch);
  memset(ch, 'L', 5);					/* 将字符串的前5个字节设为字符L */
  printf("%s\n", ch);
  return 0;
}
