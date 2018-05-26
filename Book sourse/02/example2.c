/* exampe2.c */
#include <stdio.h>
int main()
{
  int x=0;
  goto L1; 						/* 跳转语句 */
  x=1;
L1:printf("x = %d\n", x); 				/* 转向位置 */
  return 0;
}
