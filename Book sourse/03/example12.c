/* exampe12.c */
#include <stdlib.h>
#include <stdio.h>
#define M 10						/* 数组的长度 */
int main()
{
  int x[M]; 						/* 定义整型数组 */
  int i, j, min, t;
  int *p, *p1, *p2;					/* 定义指针变量 */
  printf("Please input 10 integers:\n");
  p1 = x;
  p2 = &x[M-1];
  for(; p1<=p2; p1++)				/* 输入要排序的一组数 */
  {
    scanf("%d", p1);
  }
  p = x;							/* 可以改为p=&x[0] */
  for (i=0; i<M-1; i++)
  {
    min = i;						/* 假设当前下标为i的数最小，比较后再进行调整 */
    for (j=i+1; j<M; j++)				/* 找出最小的数的下标 */
    {
      if (*(p+j) < *(p+min))			/* 使用指针来引用数组元素 */
      {
        min = j;					/* 如果后面的数比前面的小，则记下它的下标 */
      }
    }
    if (min != i)						/* 如果min在循环中改变了，则交换数据 */
    {
      t = *(p+i);
      *(p+i) = *(p+min);
      *(p+min) = t;
    }
  }
  printf("The result is:\n");
  for (i=0; i<M; i++)					/* 输出排序结果 */
  {
    printf("%d ",*(p+i));
  }
  printf("\n");
  return 0;
}
