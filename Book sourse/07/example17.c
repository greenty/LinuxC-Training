/* example17.c */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>					/* 包含函数所在头文件 */
int main()
{
  time_t tim;						/* 声明time_t结构体 */
  time(&tim);						/* 获取当前的时间 */
  printf("%s", ctime(&tim));			/* 转换为字符串格式并输出 */
  return 0;
}
