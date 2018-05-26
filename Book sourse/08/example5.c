/* example5.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>						/* 包含相关函数头文件 */
#include <error.h>
int main(int argc, char **argv)
{
  int ret;
  if(argc != 3)							/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  ret = symlink(argv[1], argv[2]);			/* 创建文件的硬连接 */
  if(ret == -1)							/* 如果硬连接创建失败，输出错误信息并退出 */
  {
    perror("创建硬连接失败");
    exit(1);
  }
  printf("完成！\n");
  return 0;
}
