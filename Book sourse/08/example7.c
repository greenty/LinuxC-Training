/* example7.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>						/* 包含相关头文件 */
int main(int argc, char **argv)
{
  if(argc != 2)							/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  if(access(argv[1], F_OK) != -1)		/* 判断文件是否存在 */
  {
    if(access(argv[1], R_OK) != -1)		/* 判断文件是否可读 */
      printf("可读\n");
    if(access(argv[1], W_OK) != -1)		/* 判断文件是否可写 */
      printf("可写\n");
    if(access(argv[1], X_OK) != -1)		/* 判断文件是否可执行 */
      printf("可执行\n");
  }
  else
  {
    printf("%s 不存在\n", argv[1]);		/* 文件不存在 */
  }
  return 0;
}
