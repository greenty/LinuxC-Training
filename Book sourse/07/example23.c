/* example23.c */
#include <stdlib.h>
#include <stdio.h>
#include<pwd.h>						/* 包含相关函数头文件 */
#include<sys/types.h>
int main()
{
  struct passwd *user;
  user = getpwent();
  while(user != NULL)				/* 读取用户账号信息 */
  {
    printf("%s:%d:%d:%s:%s:%s\n", user->pw_name, user->pw_uid, user->pw_gid,
        user->pw_gecos, user->pw_dir, user->pw_shell);\
    getchar();
    user = getpwent();
  }
  endpwent();						/* 关闭文件 */
  return 0;
}
