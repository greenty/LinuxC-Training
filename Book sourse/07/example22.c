/* example22.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数头文件 */
#include <sys/types.h>
int main()
{
  uid_t uid;
  gid_t gid;
  uid = getuid();					/* 获取当前用户的标识符 */ 
  gid = getgid();					/* 获取当前组的标识符 */
  printf("user name : %s\n", getlogin());	/* 输出当前用户的账号名称 */
  printf("uid = %d\n", uid);
  printf("gid = %d\n", gid);
  return 0;
}
