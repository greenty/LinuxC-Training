/* exampe3.c */
#include <stdio.h>
int main()
{
  int x; 							/* 定义循环控制变量 */
  for (x=0; x<100; x++)
  {
    printf ("%d\n",x);
    if (10 == x)						/* 等价于x==10 */
    {
      break;						/* 退出循环 */
    }
  }
  return 0;
}
