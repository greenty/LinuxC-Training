/* example7.c */
#include <stdio.h>						/* 包含相关函数头文件 */
#include <stdlib.h>
#define NUM 3
struct student							/* 定义结构体 */
{
  int id;
  int score;
};
int main()
{
  struct student stu[NUM];				/* 定义缓冲区 */
  int i, len;
  FILE *filp; 							/* 定义文件指针 */
  filp = fopen("./test.dat", "r");		/* 打开文件 */
  if (filp == NULL)
  {
    perror("Open test.dat failed ");	/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  len = fread(stu, sizeof(struct student), NUM, filp);		/* 从文件中读取NUM个结构体 */
  if (len != NUM) 						/* 如果实际读取长度小于NUM，输出具体原因 */
  {
    if(feof(filp)) 						/* 测试是否读到文件末尾 */
    {
      printf("End of file.");
    }
    else
    {
      printf("Read file error");		/* 输出错误信息 */
    }
  }
  printf("ID\tScore\n");
  for (i=0; i<NUM; i++)
  {
    printf("%d\t%d", stu[i].id, stu[i].score);	/* 输出各结构体数组 */
    printf("\n");
  }
  fclose(filp); 						/* 关闭文件 */
  return 0;
}
