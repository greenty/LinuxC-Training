/* example18.c */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>					/* 包含函数所在头文件 */
int main()
{
  time_t tim;
  struct tm *p;
  char *week[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  time(&tim); 					/* 获取当前的时间 */
  p = gmtime(&tim); 				/* 转换为tm结构 */
  printf("%d/%d/%d\n", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday); 	/* 输出日期 */
  printf("%s\n", week[p->tm_wday]); 								/* 输出星期 */
  printf("%d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec); 				/* 输出时间 */
  return 0;
}
