/* example21.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>							/* 包含相关函数头文件 */
int main(int argc, char * argv[])
{
  int arg;
  if(argc < 2)                /* 检查参数个数 */
  {
    printf("no arguments\n");
  }
  while ((arg = getopt(argc, argv, "ab:c")) != -1)    /* 分析各选项 */
  {
    printf("optind : %d\n", optind); 				/* 输出全局变量optind的值 */
    switch (arg)
    {
      case 'a': 							/* 选项a */
        printf("option : a\n");
        break;
      case 'b':               /* 选项c */
        printf("option : b\n");
        break;
      case 'c': 							/* 选项b，该选项必须带参数 */
        printf("option : c\n");
        printf("argument of -c : %s\n", optarg);
        break;
      default:					/* 其他选项 */
        printf("unknown option : %c\n", (char)optopt);
        break;
    }
  }
  return 0;
}

