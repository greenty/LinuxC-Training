/* server.c : tcp */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>				/* 包含相关函数头文件 */
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERV_PORT 2360			/* 服务器监听端口号 */
#define LENGTH 10				/* 请求队列的长度数 */
#define SIZE 128				/* 缓冲区的长度 */
int main()
{
  int res;
  int sockfd;						/* 定义监听Socket描述符 */
  int clientfd;						/* 定义数据传输Socket描述符 */
  struct sockaddr_in hostaddr;		/* 本机IP地址和端口号信息 */
  struct sockaddr_in clientaddr; 		/* 客户端IP地址和端口号信息 */
  unsigned int addrlen;
  char buf[SIZE];				/* 定义缓冲区 */
  int cnt;
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
  /* 将套接字设为监听模式，以等待连接请求 */
  res = listen(sockfd, LENGTH);
  if(res == -1) {
    perror("设置监听模式错误\n");
    exit(1);
  }
  printf("等待客户端请求连接。\n ");
  /* 请求到来后，接受连接请求，并接收数据 */
  while(1)
  {
    addrlen = sizeof(struct sockaddr_in);
    clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen);		/* 接受连接请求 */
    if(clientfd == -1)
    {
      perror("接受连接请求错误\n");
      continue;
    }
    printf("客户端IP : %s\n", inet_ntoa(clientaddr.sin_addr));		/* 输出客户端IP地址 */
    cnt = recv(clientfd, buf, SIZE, 0);		/* 接收数据 */
    if(cnt == -1) 					/* 如果数据接收失败，输出错误信息并退出 */
    {
      perror("数据接受失败\n");
      exit(1);
    }
    printf("收到的数据 : %s\n", buf); 		/* 输出接收到数据 */
    close(clientfd);					/* 关闭数据传输套接字 */
  }
  return 0;
}
