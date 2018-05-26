/* example3.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char **argv)
{
  mode_t auth=0750; 				/* 定义文件的访问权限 */
  int state;
  if(argc != 2)						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  state = mkfifo(argv[1], auth); 		/* 创建命名管道 */
  if(state < 0){ 					/* 如果管道创建失败，输出错误信息并退出 */
    perror("管道创建失败");
    exit(1);
  }
  else
  {
    printf("管道创建成功。\n");		/* 如果管道创建成功，输出相关信息 */
  }
  return 0;
}
