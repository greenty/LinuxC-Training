/*example5.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>						/* 包含相关函数头文件 */
#include <arpa/inet.h>
#include <netinet/in.h>
int main(int argc, char **argv)
{
  struct sockaddr_in sockaddr;
  struct hostent *host;
  if(argc != 2)								/* 检查命令行参数个数 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  inet_aton(argv[1], &sockaddr.sin_addr);					/* 将IP地址由字符串转换为二进制形式 */
  host = gethostbyaddr((char *)&sockaddr.sin_addr, 4, AF_INET);	/* 查找IP地址对应的主机信息 */
  printf("%s\n", host->h_name); 				/* 输出主机域名 */
  return 0;
}
