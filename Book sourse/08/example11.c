/* example11.c */
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>					/* 包含相关函数头文件 */
#include<error.h>
#define SIZE 64						/* 设置缓冲区大小 */
int main()
{
  int res;
  char buf[SIZE];
  getcwd(buf, sizeof(buf));			/* 获取当前工作目录 */
  printf("%s\n", buf);
  res = chdir("..");					/* 更改工作目录 */
  if(res == -1) 						/* 如果目录更改失败，输出错误信息并退出 */
  {
    perror("目录更改失败：");
    exit(1);
  }
  getcwd(buf, sizeof(buf)); 			/* 获取更改后的工作目录 */
  printf("%s\n", buf);
  return 0;
}
