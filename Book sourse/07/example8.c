/* example8.c */
#include <stdio.h>
#include <string.h>						/* 包含函数所在头文件 */
int main()
{
  char ch[] = "Linux C is very good!";
  char fo[] = "is";						/* 要查找的字串 */
  char *p;
  p = strstr(ch, fo);					/* 查找字符串 */
  if(p != NULL)
    printf("%s\n", p);					/* 输出指针p指向的子串 */
  else
    printf("Not Found!\n");				/* 没有找到 */
  return 0;
}
