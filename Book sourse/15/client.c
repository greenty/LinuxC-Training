/* client.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>       		/* 包含相关函数头文件 */
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define SERV_PORT 2395			/* 服务器监听端口号 */
#define BUF_SIZE 1024				/* 缓冲区的长度 */
#define MEM_SIZE 32

struct cpustatus					/* 处理器信息 */
{
  long total;
  float user;
  float nice;
  float system;
  float idle;
};
struct meminfo						/* 内存信息 */
{
  char total[MEM_SIZE];
  char free[MEM_SIZE];
};

int main(int argc, char **argv)
{
  int ret;
  int sockfd; 						/* 定义Socket描述符 */
  struct sockaddr_in serv_addr; 		/* 服务器IP地址和端口号信息 */
  char buf[BUF_SIZE];				/* 定义缓冲区 */
  struct cpustatus cpu_stat;
  struct meminfo mem_info;
  int cnt;
  int size;
  if(argc != 2) 						/* 检查命令行参数个数是否正确 */
  {
    printf("参数错误。\n");
    exit(1);
  }
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) 							/* 如果套接字创建失败，输出错误信息并退出 */
  {
    printf("套接字创建失败。\n");
    exit(1);
  }
  /* 向服务器发出连接请求 */
  serv_addr.sin_family = AF_INET; 				/* TCP/IP协议 */
  serv_addr.sin_port = htons(SERV_PORT); 		/* 服务器端口号，并转换为网络字节顺序 */
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]); 	/* 服务器的IP地址 */
  bzero(&(serv_addr.sin_zero), 8); 				/* 清零 */
  ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)); 	/* 连接 */
  if(ret == -1) 								/* 如果连接失败，输出错误信息并退出 */
  {
    printf("连接失败。\n");
    exit(1);
  }
  /* 接收数据 */
  cnt = recv(sockfd, buf, BUF_SIZE, 0);
  if(cnt == -1)
  {
    perror("接收数据失败。\n");
    exit(1);
  }
  size  = sizeof(struct cpustatus);
  memcpy(&cpu_stat, buf, size);
  memcpy(&mem_info, buf+size, sizeof(struct meminfo));
  /* 输出接收到数据 */
  printf("CPU信息\n");
  printf("------------------------\n");
  printf("user:\t\t %.2f%%\n", cpu_stat.user);
  printf("nice:\t\t %.2f%%\n", cpu_stat.nice);
  printf("system:\t\t %.2f%%\n", cpu_stat.system);
  printf("idle:\t\t %.2f%%\n", cpu_stat.idle);
  printf("内存信息\n");
  printf("------------------------\n");
  printf("total:\t\t %s kB\n",mem_info.total);
  printf("free:\t\t %s kB \n",mem_info.free);
  close(sockfd); 					/* 关闭套接字 */
  return 0;
}
