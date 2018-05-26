/* exampe13.c */
#include <stdlib.h>
#include <stdio.h>
#define C 3						/* 二维数组的行数 */
#define R 4						/* 二维数组的列数 */
int main()
{
  int i, j;
  int a[C][R];
  int *p1, *p2; 						/* 定义指向整型变量的指针 */
  int **p = &p2;						/* 定义指向指针的指针变量 */
  int x, y;
  int max = 0;
  for(i=0; i<C; i++)					/* 输入二维数组的元素 */
  {
    printf("Row %d:\n", i+1);
    for(j=0; j<R; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  for(i=0; i<C; i++)
  {
    p1 = &a[i][R-1];					/* 指向每行的最后一个元素 */
    for(p2=&a[i][0]; p2<=p1; p2++)
    {
      if (**p > max)					/* 求最大值及位置 */
      {
        max = **p;
        x = i + 1;
        y = R - (p1 - p2);				/* 指针运算 */
      }
    }
  }
  printf("Max: %d (%d,%d)", max, x, y);	/* 输出所有元素的最大值及其位置 */
  return 0;
}
