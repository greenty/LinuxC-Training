/* example6.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
int main()
{
  char ch1[] = "Linux c is very good!";			/* 定义并初始化字符数组ch1 */
  char ch2[] = "Linux C is very good!";
  int res;							/* 用来保存strcmp函数的返回值 */
  printf("ch1 : %s\n", ch1);
  printf("ch2 : %s\n", ch2);
  res = strcmp(ch1, ch2);				/* 比较两个字符串 */
  if(res == 0)						/* 字符串ch1与ch2相同 */
    printf("ch1 and ch2 are identical\n");
  else if(res < 0) 					/* 字符串ch1比ch2小 */
    printf("ch1 less than ch2\n");
  else							/* 字符串ch1与ch2大 */
    printf("ch1 greater than ch2\n");
  return 0;
}

