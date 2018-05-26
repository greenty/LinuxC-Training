/* example6.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>						/* 包含相关函数头文件 */
#include <sys/stat.h>
int main(int argc, char **argv)
{
  struct stat sta;
  if(argc != 2)							/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  stat(argv[1], &sta);					/* 获取文件的属性 */
  printf("文件大小： %ld Byte\n", sta.st_size);	/* 输出文件的大小 */
  printf("文件类型： ");
  switch(sta.st_mode & S_IFMT)			/* 判断文件的类型 */
  {
    case S_IFSOCK:						/* 套接字 */
      printf("套接字\n");
      break;
    case S_IFLNK: 						/* 符号连接 */
      printf("符号连接\n");
      break;
    case S_IFREG: 						/* 普通文件 */
      printf("普通文件\n");
      break;
    case S_IFBLK: 						/* 块设备文件 */
      printf("块设备\n");
      break;
    case S_IFDIR: 						/* 目录文件 */
      printf("目录文件\n");
      break;
    case S_IFCHR: 						/* 字符设备文件 */
      printf("字符设备文件\n");
      break;
    case S_IFIFO: 						/* 管道文件 */
      printf("管道文件\n");
      break;
    default:
      ;
  }
  return 0;
}
