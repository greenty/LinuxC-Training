/* example24.c */
#include <stdlib.h>
#include <stdio.h>
#include <utmp.h>					/* 包含相关函数头文件 */
int main()
{
  struct utmp *user;
  while((user = getutent()) != NULL)
  {
    if(user->ut_type == USER_PROCESS)	/* 判断是否为普通用户进程 */
      printf("%s\t is %s \n", user->ut_user, user->ut_line);
  }
  endutent();						/* 关闭文件 */
  return 0;
}
