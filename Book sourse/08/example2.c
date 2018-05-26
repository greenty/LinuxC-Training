/* example2.c */
#include <stdlib.h>
#include <stdio.h>
#include <error.h>					/* 包含相关函数头文件 */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
  int fol;							/* 定义文件描述符 */
  fol = open("file", O_CREAT | O_EXCL, 00750);
  if (fol == -1)
  {
    perror("打开文件失败");				/* 如果文件打开失败，调用perror函数输出错误信息 */
    exit(1);
  }
  return 0;
}
