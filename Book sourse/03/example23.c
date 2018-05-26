/* exampe23.c */
#include <stdlib.h>
#include <stdio.h>
int fun(int);						/* 函数声明 */
int main()
{
  int n,x;
  printf("Input n (>0) : ");
  scanf("%d", &n); 					/* 输入正整数n */
  if(n <= 0)						/* 如果输入数据的为负数或零，输出错误信息 */
  {
    printf("Error!\n");
  }
  else
  {
    x = fun(n); 					/* 函数调用 */
    printf("%d! = %d \n", n, x);			/* 输出运算结果 */
  }
  return 0;
}
int fun(int i) 						/* 函数定义 */
{
  int t;
  if(1 == i)						/* 递归结束条件 */
  {
    return 1;
  }
  else
  {
    t = i*fun(i-1);					/* 函数递归调用 */
    return t;
  }
}
