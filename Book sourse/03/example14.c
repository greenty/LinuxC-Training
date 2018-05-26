/* exampe14.c */
#include <stdlib.h>
#include <stdio.h>
int main()
{
  int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};			/* 定义二维数组并初始化 */
  int *pa[3]={a[0],a[1],a[2]};				/* 定义指针数组，分别指向二维数组a的每一行 */
  /*int *pa[3]={&a[0][0],&a[1][0],&a[2][0]};*/		/* 和上面的语句等效，给读者一个参考 */
  int *pb;
  int i, j,m;
  for(i=0; i<3; i++)
  {
    pb=pa[i]; 							/* pb指向当前行 */
    for (j=1; j<3; j++)
    {
      if (*pa[i] < *(++pb)) 				/* *pa[i]和*(++pb)都是对二维数组元素的引用 */
      {
        pa[i]=pb;						/* 确保pa[i]指向当前行的最大值 */
      }
    }
    printf("Line%d: %d\n",i+1,*pa[i]);
  }
  m=*pa[0];
  for(i=0; i<3; i++)		/* 比较pa数组所指向的各行最大值，进而求出整个数组的最大值 */
  {
    if(m<*pa[i])
    {
      m=*pa[i];
    }
  }
  printf("Max: %d\n",m);
  return 0;
}
