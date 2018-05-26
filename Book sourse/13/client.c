/* client.c : tcp */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>			/* 包含相关函数头文件 */
#include <sys/socket.h>
#define SERV_PORT 2369			/* 服务器监听端口号 */
#define SIZE 128				/* 缓冲区的长度 */
int main(int argc, char **argv)
{
  int res;
  int sockfd; 						/* 定义Socket描述符 */
  struct sockaddr_in servaddr; 		/* 服务器IP地址和端口号信息 */
  char buf[SIZE];				/* 定义缓冲区 */
  int cnt;
  if(argc != 2) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) 							/* 如果套接字创建失败，输出错误信息并退出 */
  {
    perror("套接字创建失败\n");
    exit(1);
  }
  /* 向服务器发出连接请求 */
  servaddr.sin_family = AF_INET; 				/* TCP/IP协议 */
  servaddr.sin_port = htons(SERV_PORT); 		/* 服务器端口号，并转换为网络字节顺序 */
  servaddr.sin_addr.s_addr = INADDR_ANY; 	/* 这里我们使用回环地址，即127.0.0.1 */
  bzero(&(servaddr.sin_zero), 8); 				/* 清零 */
  res = connect(sockfd,						/* 建立连接 */
       (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
  if(res == -1) 						/* 如果连接失败，输出错误信息并退出 */
  {
    perror("连接失败\n");
    exit(1);
  }
  /* 发送数据 */
  strcpy(buf, argv[1]);
  cnt = send(sockfd, buf, SIZE, 0);
  if(cnt == -1) 						/* 如果数据发送失败，输出错误信息并退出 */
  {
    perror("数据发送失败\n");
    exit(1);
  }
  printf("发送数据： %s\n", buf); 			/* 输出所发送的字符串 */
  close(sockfd); 					/* 关闭套接字 */
  return 0;
}
