/* example2.c */
#include <stdio.h>					/* 包含相关函数头文件 */
#include <stdlib.h>
int main()
{
  FILE *filp; 						/* 定义文件指针 */
  int text;
  filp = fopen("./test", "w+");		/* 打开文件 */
  if (filp == NULL)
  {
    perror("打开文件失败：");	/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  while ((text=getchar()) != '!')	/* 从键盘读入字符，直到输入“!”结束 */
  {
    fputc(text, filp); 				/* 将读入的字符写到文件之中 */
  }
  rewind(filp);						/* 重设读写位置 */
  while ( (text=fgetc(filp)) != EOF)/* 将文件内容一个字节一个字节地读出来，直到文件结束 */
  {
    putchar(text); 					/* 将读出的字符输出到屏幕 */
  }
  fclose(filp);
  return 0;
}
