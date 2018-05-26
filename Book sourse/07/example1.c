/* example1.c */
#include <stdio.h>
#include <ctype.h>
int main()
{
  char s[] = "cD1-5$XT_et";			/* 定义字符数组 */
  int i;
  for (i=0; s[i]!=0; i++)				/* 遍历数组中的每个字符 */
  {
    if (isalpha(s[i]))					/* 测试字符是否为英文字母 */
    {
      printf("%d : %c \n", i, s[i]);
    }
  }
  return 0;
}
