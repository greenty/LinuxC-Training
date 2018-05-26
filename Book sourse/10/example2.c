/* example7.c */
#include <stdio.h>
#include <stdlib.h>						/* 包含相关函数头文件 */
#define SIZE 1024
int main()
{
  char buf[SIZE];
  FILE *p;
  char *cmd = "ps -f";					/* 命令字符串 */
  if( (p = popen(cmd, "r")) == NULL )	/* 将命令的输出通过管道读取到p之中 */
  {
    printf("popen error!\n");
    exit(1);
  }
  while(fgets(buf, sizeof(buf), p))		/* 将p中的数据流读取到缓冲区中 */
  {
    printf("%s", buf);
  }
  pclose(p);
  return 0;
}
