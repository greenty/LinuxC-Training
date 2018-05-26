/* exampe1.c */
#include <stdio.h>
int main()
{
  char x;
  x='\0';
  while (x!='q')						/* 使用字母q结束循环*/ 
  {
    x=getchar();					/* 从键盘接受字符，并回显 */
  }
  return 0;
}
