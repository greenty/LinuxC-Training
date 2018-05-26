/* example13.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
  char ch1[] = "1111";
  char ch2[] = "2222";
  char ch3[] = "ABCD";
  printf("ch1 = %ld\n", strtol(ch1, NULL, 2));			/* 二进制 */
  printf("ch2 = %ld\n", strtol(ch2, NULL, 10)); 			/* 十进制 */
  printf("ch3 = %ld\n", strtol(ch3, NULL, 16)); 			/* 十六进制 */
  return 0;
}
