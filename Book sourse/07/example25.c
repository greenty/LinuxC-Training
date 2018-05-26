/* example25.c */
#include <stdlib.h>					/*  包含相关函数头文件 */
#include <stdio.h>
int main()
{
  char *p;
  p = getenv("SHELL");				/* 获取环境变量 */
  if(p == NULL)					/* 如果环境变量获取失败，输出错误信息并退出 */
  {
    printf("getenv error\n");
    exit(1);
  }
  else
    printf("SHELL=%s\n", p); 			/* 输出环境变量的内容 */
  return 0;
}
