/* test.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>							/* 包含相关函数头文件 */
int main(int argc, char *argv[])
{
  int i;
  for(i=0; i<argc; i++)
  {
    printf("arg%d : %s\n", i, argv[i]); 	/* 输出各命令行参数 */
  }
  char **penv = __environ;
  while(penv && *penv)
  {
    printf("%s\n", *penv++);				/* 输出系统的各环境变量 */
  }
  return 0;
}
