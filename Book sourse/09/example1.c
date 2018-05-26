/* example1.c */
#include <stdio.h>					/* 包含相关函数头文件 */
#include <stdlib.h>
int main()
{
  FILE *filp;							/* 定义文件指针 */
  filp = fopen("./file", "r");		/* 打开文件 */
  if (filp == NULL) 					/* 如果文件打开失败，输出错误信息并退出 */
  {
    printf("打开文件失败。\n");
    exit(1);
  }
  printf("打开文件成功。\n");
  fclose(filp); 						/* 关闭文件 */
  return 0;
}
