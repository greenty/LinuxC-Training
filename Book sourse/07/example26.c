/* example26.c */
#include <stdlib.h>						/* 包含相关函数头文件 */
#include <stdio.h>
int main(int argc, char * argv[])
{
  char * p;
  if(argc != 3) 						/* 检查命令行参数个数 */
  {
    printf("no arguments\n");
    exit(1);
  }
  if((p=getenv(argv[1])) == NULL) 		/* 获取并输出环境变量 */
    printf("%s does not exist\n", argv[1]);
  else
    printf("%s=%s\n", argv[1], p);
  setenv(argv[1], argv[2], 1); 			/* 设置环境变量 */
  if((p=getenv(argv[1])) != NULL) 		/* 重新获取并输出环境变量 */
  {
    printf("%s=%s\n", argv[1], p);
  }
  return 0;
}
