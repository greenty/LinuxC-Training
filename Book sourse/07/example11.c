/* example11.c */
#include <stdio.h>
#include <ctype.h>						/* 包含函数所在头文件 */
int main()
{
  char ch[] = "Linux C is very good!";			/* 定义字符串 */
  int i;
  printf("%s\n", ch); 					/* 输出转换前的字符串 */
  for(i=0; i<sizeof(ch); i++)
  {
    ch[i] = toupper(ch[i]); 				/* 全部转换为大写字母 */
  }
  printf("%s\n", ch); 					/* 输出转换后的字符串 */
  for(i=0; i<sizeof(ch); i++)
  {
    ch[i] = tolower(ch[i]); 				/* 全部转换为小写字母 */
  }
  printf("%s\n", ch); 					/* 输出转换后的字符串 */
  return 0;
}
