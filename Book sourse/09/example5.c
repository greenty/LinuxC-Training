/* example5.c */
#include <stdio.h>					/* 包含相关函数头文件 */
#include <stdlib.h>
#define SIZE 256
int main(int argc, char **argv)
{
  char buffer[SIZE]; 				/* 定义缓冲区 */
  FILE *filp1, *filp2; 				/* 定义文件指针 */
  if(argc != 3)
  {
    printf("参数太少。\n");
  }
  filp1 = fopen(argv[1], "r");		/* 打开源文件 */
  if (filp1 == NULL)
  {
    perror("文件1打开失败：");	/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  filp2 = fopen(argv[2], "w");		/* 打开目标文件 */
  if (filp2 == NULL)
  {
    perror("文件2打开失败：");	/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  while (!feof(filp1))				/* 测试是否读到文件末尾 */
  {
    fgets(buffer, SIZE, filp1);		/* 逐行读取源文件内容尾 */
    fputs(buffer, filp2);			/* 逐行写入到目标文件之中 */
  }
  fclose(filp1); 					/* 关闭源文件 */
  fclose(filp2); 					/* 关闭目标文件 */
  printf("完成！\n");
  return 0;
}
