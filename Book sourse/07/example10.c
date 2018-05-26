/* example10.c */
#include <stdio.h>
#include <string.h>					/* 包含函数所在头文件 */
int main()
{
  char ch[] = "Linux C is very good!";
  char *p;
  p = strtok(ch, " ");					/* 以空格对字符串进行分割 */
  while(p != NULL)
  {
    printf("%s\n", p); 				/* 输出分割后的子串 */
    p = strtok(NULL, " ");
  }
  printf("ch : %s\n", ch);
  return 0;
}
