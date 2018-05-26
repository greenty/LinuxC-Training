/* example6.c */
#include <stdio.h>					/* 包含相关函数头文件 */
#include <stdlib.h>
#define LEN 3
struct student						/* 定义结构体 */
{
  int id;
  int score;
};
int main()
{
  struct student array[LEN];				/* 定义结构体数组 */
  int i, sum;
  FILE *filp; 						/* 定义文件指针 */
  filp = fopen("./test.dat", "w");			/* 打开文件 */
  if (filp == NULL)
  {
    perror("打开test.dat文件失败：");		/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  for(i=0; i<LEN; i++)					/* 初始化结构体 */
  {
    printf("ID：");
    scanf("%d", &array[i].id);
    printf("分数：");
    scanf("%d", &array[i].score);
  }
  sum = fwrite(array, sizeof(struct student), LEN, filp); 		/* 将结构体数组写入到文件之中 */
  if (sum != LEN)
  {
    printf("写入失败。");			/* 如果写入失败，输出信息 */
  }
  fclose(filp); 						/* 关闭文件 */
  return 0;
}
