/* example3.c */
#include <stdio.h>
#include <stdlib.h>					/* 包含相关函数头文件 */
int main()
{
  FILE *filp; 						/* 定义文件指针 */
  int i, text, pos;
  filp = fopen("./test", "r");				/* 打开文件 */
  if (filp == NULL)
  {
    perror("打开文件失败：");			/* 如果文件打开失败，输出错误信息 */
    exit(1);
  }
  for (i=0; i<=7; i+=2)
  {
    fseek(filp, i, SEEK_SET); 			/* 重设读写位置 */
    pos = ftell(filp); 					/* 获取当前的读写位置 */
    printf("当前读写位置： %d\n", pos+1);
    text=fgetc(filp); 					/* 从文件读入一个字节 */
    printf("字符：");
    putchar(text); 					/* 将字符输出到屏幕 */
    printf("\n");
  }
  fclose(filp); 						/* 关闭文件 */
  return 0;
}
