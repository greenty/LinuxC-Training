/* example12.c */				
#include <stdio.h>
#include <stdlib.h>						/* 包含函数所在头文件 */
int main()
{
  char ch1[] = "-139";
  char ch2[] = "0xff";					/* 转换后结果为0，因此只转换到字符x */
  int res;
  res = atoi(ch1) + atoi(ch2);				/* 将两个字符串转换为整数并求和 */
  printf("res = %d\n", res); 				/* 输出计算结果 */
  return 0;
}
