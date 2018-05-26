/* example8.c */
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <sys/types.h>					/* 包含相关函数头文件 */
#include <sys/stat.h>
int main(int argc, char **argv)
{
  int res;
  if(argc != 2)							/* 检查命令行参数个数 */
  {
    printf("参数太少\n");
    exit(1);
  }
  res = chmod(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);	 /* 修改文件的访问权限 */
  if(res == -1)							/* 如果文件权限修改失败，输出错误信息并退出 */
  {
    perror("权限修改失败：");
    exit(1);
  }
  printf("完成！\n");
  return 0;
}
