/* exampe5.c */
#include <stdio.h>
#define M 3
#define N 4
int main()
{
  int x[N][M];						/* 定义二维数据，用于存放原始矩阵 */
  int y[M][N]; 						/* 定义二维数据，用于存放转置矩阵 */
  int i, j;
  printf("Please Input %d * %d integers:\n",M,N);
  for(i=0;i<N;i++) 					/* 两层循环，遍历二维数组x的各个元素 */
  {
    for(j=0;j<M;j++)
    {
      scanf("%d",&x[i][j]); 			/* 从键盘读入二维数组x中各元素的值，&为地址运算符 */
    }
  }
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      y[j][i]=x[i][j]; 					/* 矩阵转置 */
    }
  }
  for(i=0;i<M;i++)
  {
    for(j=0;j<N;j++)
    {
      printf("%d ",y[i][j]);				/* 将转置矩阵y输出 */
    }
    printf("\n");						/* 每行输出完成后换行 */
  }
  return 0;
}
