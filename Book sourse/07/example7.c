/* example7.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
int main()
{
  char ch[] = "Linux C is very good!";				/* 定义并初始化字符数组 */
  char *p;							/* 定义字符指针 */
  p = index(ch, 'g');					/* 在字符串s中查找字符g */
  printf("%s\n", p);
  return 0;
}
