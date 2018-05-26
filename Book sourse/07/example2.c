/* example2.c */
#include <stdio.h>
#include <ctype.h>					/*包含函数所在头文件*/
int main()
{
  int str;
  printf("Input the characters :\n");
  for(;;)
  {
    str = getchar();					/* 从键盘获取字符 */
    printf("%c : %s digit\n", str, isdigit(str)?"is":"not");		/* 测试字符是否为数字 */
  }
  return 0;
}
