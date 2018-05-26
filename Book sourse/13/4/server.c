/* server.c : udp */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>			/* 包含相关函数头文件 */
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERV_PORT 2370			/* 端口号 */
#define SIZE 128				/* 缓冲区的长度 */
int main()
{
  int res;
  int sockfd;						/* 定义Socket描述符 */
  struct sockaddr_in hostaddr;		/* 主机IP地址和端口号 */
  struct sockaddr_in clientaddr; 		/* 客户端IP地址和端口号 */
  unsigned int addrlen;
  char buf[SIZE];				/* 定义缓冲区 */
  int cnt;
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd == -1) 					/* 如果套接字创建失败，输出错误信息并退出 */
  {
    perror("套接字创建失败\n");
    exit(1);
  }
  /* 将套接字与IP地址和端口号进行绑定 */
  hostaddr.sin_family = AF_INET;				/* TCP/IP协议 */
  hostaddr.sin_port = htons(SERV_PORT);		/* 让系统随机选择一个未被占用的端口号 */
  hostaddr.sin_addr.s_addr = INADDR_ANY;		/* 本机IP地址 */
  bzero(&(hostaddr.sin_zero), 8);				/* 清零 */
  res = bind(sockfd, (struct sockaddr *)&hostaddr, sizeof(struct sockaddr));	/* 绑定 */
  if(res == -1) 								/* 如果套接字绑定失败，输出错误信息并退出 */
  {
    perror("套接字绑定失败\n");
    exit(1);
  }
  /* 循环接收UDP数据 */
  while(1)
  {
    addrlen = sizeof(struct sockaddr_in);
    cnt = recvfrom(sockfd, buf, SIZE, 0,		/* 接收数据*/
       (struct sockaddr *)&clientaddr, &addrlen);
    if(cnt == -1) 							/* 如果数据接收失败，输出错误信息并退出 */
    {
      perror("数据接收失败\n");
      continue;
    }
    printf("客户端IP： %s\n", inet_ntoa(clientaddr.sin_addr));	/* 输出客户端IP地址 */
    printf("收到的数据： %s\n", buf); 				/* 输出接收到数据 */
  }
  close(sockfd);							/* 关闭套接字 */
  return 0;
}
