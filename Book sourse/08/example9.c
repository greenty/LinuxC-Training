/* example9.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>						/* 包含相关函数头文件 */
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
  int res;
  if(argc != 2)							/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  res = mkdir(argv[1], S_IRUSR | S_IXUSR);	/* 创建目录文件 */
  if(res == -1)							/* 如果目录文件创建失败，输出错误信息并退出 */
  {
    perror("创建目录失败：");
    exit(1);
  }
  printf("完成！\n");
  return 0;
}
