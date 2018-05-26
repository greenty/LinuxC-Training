/* client.c : udp */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>				/* 包含相关函数头文件 */
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERV_PORT 2370			/* 端口号 */
#define SIZE 128				/* 缓冲区的长度 */
int main(int argc, char **argv)
{
  int sockfd; 						/* 定义Socket描述符 */
  struct sockaddr_in servaddr; 		/* 服务器IP地址和端口号 */
  unsigned int addrlen;
  char buf[SIZE];				/* 定义缓冲区 */
  int cnt;
  if(argc != 3) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd == -1) 					/* 如果套接字创建失败，输出错误信息并退出 */
  {
    perror("套接字创建失败\n");
    exit(1);
  }
  /*发送UDP数据*/
  servaddr.sin_family = AF_INET; 				/* TCP/IP协议 */
  servaddr.sin_port = htons(SERV_PORT); 		/* 服务器的端口号 */
  servaddr.sin_addr.s_addr = inet_addr(argv[1]); 	/* 服务器的IP地址 */
  bzero(&(servaddr.sin_zero), 8); 				/* 清零 */
  addrlen = sizeof(struct sockaddr_in);
  strcpy(buf, argv[2]);
  cnt = sendto (sockfd, buf, SIZE, 0,			/* 发送数据 */
      (struct sockaddr *)&servaddr, addrlen);
  if(cnt == -1) 								/* 如果数据发送失败，输出错误信息并退出 */
  {
    perror("数据发送失败\n");
    exit(1);
  }
  printf("发送数据：%s\n", buf); 					/* 输出所发送的字符串 */
  close(sockfd); 							/* 关闭套接字 */
  return 0;
}
