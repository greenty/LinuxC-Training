/* exampe4.c */
#include <stdio.h>
int main()
{
  int x; 							/* 定义循环控制变量 */
  int sum=0;
  for (x=0; x<4; x++)
  {
    if (2 == x)
    {
      continue; 					/* 跳出本次循环 */
    }
    sum+=x; 						/* 求和 */
  }
  printf ("sum = %d\n",sum); 			/* 输出计算结果 */
  return 0;
}
