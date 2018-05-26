/* example10.c */
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>						/* 包含相关函数头文件 */
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc, char **argv)
{
  DIR *opdir;
  struct dirent *dirp;
  if(argc != 2) 						/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  opdir = opendir(argv[1]);				/* 打开目录文件 */
  if(opdir == NULL) 					/* 如果目录文件打开失败，输出错误信息并退出 */
  {
    perror("打开目录失败：");
    exit(1);
  }
  while((dirp = readdir(opdir)) != NULL)/* 读取目录文件 */
  {
    if((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0))	/* 跳过当前目录和父文件 */
      continue;
    if(dirp->d_type == DT_DIR) 			/* 子目录 */
    {
      printf("%s <directory>\n", dirp->d_name);
    }
    else								/* 普通文件 */
      printf("%s\n", dirp->d_name);
  }
  closedir(opdir); 						/* 关闭目录文件 */
  return 0;
}
