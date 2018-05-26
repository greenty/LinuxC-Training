/* example15.c */
#include <stdio.h>
#include <stdarg.h>

int myprintf(char *format, ...) 	/* 定义可变参数函数 */
{
  va_list vp; 						/* 定义指向可变参数列表的指针 */
  int n;
  va_start(vp, format); 			/* 使指针指向参数列表中的第一个可选参数 */
  n = vprintf(format, vp);			/* 调用vprintf函数，通过va_list传入输入参数 */
  va_end(vp);
  return n;
}

int main()
{
  int x = 66;
  float y = 0.36;
  char *z = "ABCD";
  myprintf("x = %d\ny = %g\nz = %s\n", x, y, z);	/* 调用前面定义的myprintf函数，将数据输出到屏幕 */
  return   0;
}
