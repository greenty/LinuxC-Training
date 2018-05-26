/* exampe6.c */
#include <stdio.h>
#define MAX(m,n) (m>n)?m:n			/* 定义带参数的宏 */
int main()
{
  int i,j,max;						/* 定义3个整型变量 */
  printf("Please input two integers: ");
  scanf("%d%d",&i,&j);				/* 从键盘读入两个整数 */
  max=MAX(i,j);	 				/* 用实际参数x和y替换上面的形式参数m和n,展开后的形式为：max=(i>j)?i:j; */
  printf("Max = %d\n",max); 			/* 输出最大值 */
  return 0;
}
