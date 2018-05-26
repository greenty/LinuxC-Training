/* example5.c */
#include <stdio.h>
#include <string.h>						/*包含函数所在头文件*/
int main()
{
  char ch[] = "Linux C is very good!";		/* 定义并初始化字符数组 */
  printf("%s\n", ch);
  memmove(ch, ch+11, strlen(ch)-11);		/* 字符串复制，这里源指针和目标指针指向的内存区域有重叠 */
  ch[strlen(ch)-11] = '\0';					/* 字符串结束符 */
  printf("%s\n", ch);
  return 0;
}
