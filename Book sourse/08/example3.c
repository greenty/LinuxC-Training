/* example3.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>				/* 包含相关函数头文件 */
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define SIZE 256			/* 缓冲区大小，这里设置为256，主要是为了使程序进行多次循环 */
int main(int argc, char **argv)
{
  int fol1, fol2; 						/* 定义文件描述符 */
  int cpy, wri;
  char buffer[SIZE]; 					/* 定义缓冲区 */
  char *ptr;
  if(argc != 3) 						/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  fol1 = open(argv[1], O_RDONLY); 		/* 打开源文件 */
  if (fol1 == -1)						/* 如果源文件打开失败，输出错误信息并退出 */
  {
    perror("打开文件1失败");
    exit(1);
  }
  fol2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);		/* 创建/打开目标文件 */
  if (fol2 == -1) 						/* 如果目标文件创建/打开失败，输出错误信息并退出 */
  {
    perror("打开文件2失败");
    exit(1);
  }
  while((cpy = read(fol1, buffer, SIZE)) != 0) 	/* 进行文件拷贝，首先从源文件中读取数据 */
  {
    if(cpy == -1)					/* 读取过程中有错误发生 */
    {
      perror("读取错误");
      break;
    }
    else if(cpy > 0)					/* 读取成功，数据的长度为cpy */
    {
      ptr = buffer;
      while((wri = write(fol2, ptr, sizeof(ptr))) != 0)			/* 将读取的数据写入到目标文件之中 */
      {
        if(wri == -1) 				/* 写入过程中有错误发生，跳出内层循环*/
        {
          perror("写入错误");
          break;
        }
        else if(wri == cpy) 			/* 写入字节数与读取字节数相同，数据全部写入 */
          break;
        else if(wri > 0) 				/* 写入字节数小于读取字节数，只有部分数据写入 */
        {
          ptr += wri;				/* 指向未写入的数据，接下来再次执行写入操作 */
          cpy -= wri;
        }
      }
      if(wri == -1) 				/* 写入过程中有错误发生，跳出外层循环 */
        break;
    }
  }
  close(fol1); 						/* 关闭源文件 */
  close(fol2); 						/* 关闭目标文件 */
  printf("完成！\n");
  return 0;
}
