/* example1.c */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>					/* 包含相关函数头文件 */
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
  int fol;							/* 定义文件描述符 */
  /* 打开文件，如果文件不存在，则创建一个新文件，并用后面的选项设置其访问权限 */
  //fol = open("file", O_CREAT, S_IRWXU | S_IRGRP | S_IXGRP );
  fol = open("file", O_CREAT, 00777);
  printf("fol = %d\n", fol);
  return 0;
}
