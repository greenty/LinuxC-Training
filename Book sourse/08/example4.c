/* example4.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <string.h>
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define NAME_LEN 16
#define STUDENT_NUM 32
struct student
{
  unsigned int id; 					/* 学号 */
  char name[NAME_LEN]; 				/* 姓名 */
};
int main(int argc, char **argv)
{
  int fol; 							/* 定义文件描述符 */
  struct student stu;				/* 定义结构体 */
  int id;
  char name[NAME_LEN];
  if(argc != 2)						/* 检查命令行参数个数 */
  {
    printf("参数太少。\n");
    exit(1);
  }
  fol = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);	 	/* 创建文件 */
  if (fol == -1) 					/* 如果文件创建失败，输出错误信息并退出 */
  {
    perror("打开文件失败");
    exit(1);
  }
  printf("请输入学生信息：\n");
  for(;;)							/* 循环写入学生信息 */
  {
    printf("ID : ");
    scanf("%d", &id);				/* 从键盘输入学生的学号 */
    if(id < 0) 						/* 如果输入的学号为负值，退出程序 */
    {
      printf("输入完成！\n");
      exit(0);
    }
    else
    {
      printf("名字： ");
      scanf("%16s", name); 			/* 从键盘输入学生的姓名 */
      stu.id = id;
      bzero(stu.name, NAME_LEN); 	/* 将std结构中的name清零 */
      strcpy(stu.name, name);		/* 将输入的姓名复制到std结构中 */
      lseek(fol, id*sizeof(stu), SEEK_SET); 		/* 根据学生的学号设置文件的写入位置 */
      write(fol, (char *)&stu, sizeof(stu));			/* 将学号，姓名写入到文件中 */
    }
  }
  close(fol); 						/* 关闭文件 */
  return 0;
}
