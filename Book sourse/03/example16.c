/* exampe16.c */
#include <stdlib.h>
#include <stdio.h>
void swap(int *x,int *y); 			/* 函数声明 */
int main(void)
{
  int i=1, *pa=&i;
  int j=2, *pb=&j;
  swap(pa,pb); 				/* 函数调用，传递的实际参数为指针变量 */
  printf("i = %d\nj = %d\n",i,j);
  return 0;
}
void swap(int *x, int *y) 			/* 函数定义，交换两个参数所指向的内存中的值 */
{
  int t;
  t = *x;
  *x = *y;
  *y = t ;
}
