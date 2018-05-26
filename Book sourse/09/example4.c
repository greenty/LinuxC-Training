/* example4.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含相关函数头文件 */
#define SIZE 256
int main()
{
  char buffer[SIZE];				/* 定义缓冲区 */
  int j;
  FILE *filp; 						/* 定义文件指针 */
  filp = fopen("./hello.c", "r");	/* 打开文件 */
  if (filp == NULL)
  {
    perror("文件打开失败：");	/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  j = 1;
  while (fgets(buffer, SIZE, filp) != NULL)		/* 逐行读取文件内容 */
  {
    printf("%d: %s", j++, buffer);	/* 输出各行内容 */
  }
  fclose(filp); 					/* 关闭文件 */
  return 0;
}
