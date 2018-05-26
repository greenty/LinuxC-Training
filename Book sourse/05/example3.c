/* example3.c */
#include <stdio.h>
int main()
{
  int i=1;
  int j=0; 
  int k=1;
  if (k || i && j)	/* 对于运算符优先级不是特别清楚的程序员会在这里出错，所以编译器会建议加上括号 */
  {
     ;
  }
  if (i == 1)
    if (j == 1)
      ;
  else			/* 这里的距离else最近的if语句，即if (j == 1)，为了避免错误，编译器会建议加上括号 */
    ; 
  return 0;
}
