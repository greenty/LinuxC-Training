/* server.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>			/* 包含相关函数头文件 */
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERV_PORT 2395		/* 服务器监听端口号 */
#define BACKLOG 10			/* 请求队列的长度数 */
#define BUF_SIZE 1024		/* 缓冲区的长度 */
#define MEM_SIZE 32

struct cpustatus
{
  long total; 				/* 系统从启动到现在的总时间 */
  float user;				/* 系统从启动到现在用户态的CPU时间（百分比） */
  float nice; 				/* 系统从启动到现在Nice值为负的进程所占用的CPU时间（百分比） */
  float system; 			/* 系统从启动到现在核心态的CPU时间（百分比） */
  float idle; 				/* 系统从启动到现在除I/O等待以外的其他等待时间（百分比） */
};
struct meminfo
{
  char total[MEM_SIZE]; 		/* 系统的总内存空间 */
  char free[MEM_SIZE]; 			/* 系统的空闲内存空间 */
};
void get_cpu_status(struct cpustatus *);	/* 获取处理器信息 */
void get_mem_info(struct meminfo *);	/* 获取内存信息 */

int main()
{
  int ret;
  int pid; 							/* 定义进程标识符 */
  int sockfd;						/* 定义监听Socket描述符 */
  int clientsfd;						/* 定义数据传输Socket描述符 */
  struct sockaddr_in host_addr;		/* 本机IP地址和端口号信息 */
  struct sockaddr_in client_addr; 		/* 客户端IP地址和端口号信息 */
  unsigned int addrlen;
  char buf[BUF_SIZE];				/* 定义缓冲区 */
  struct cpustatus cpu_stat;
  struct meminfo mem_info;
  int cnt;
  int size;
  /* 创建套接字 */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) 					/* 如果套接字创建失败，输出错误信息并退出 */
  {
    printf("套接字创建失败。\n");
    exit(1);
  }
  /* 将套接字与IP地址和端口号进行绑定 */
  host_addr.sin_family = AF_INET;				/* TCP/IP协议 */
  host_addr.sin_port = htons(SERV_PORT);		/* 让系统随机选择一个未被占用的端口号 */
  host_addr.sin_addr.s_addr = INADDR_ANY;		/* 本机IP地址 */
  bzero(&(host_addr.sin_zero), 8);				/* 清零 */
  ret = bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr));	/* 绑定 */
  if(ret == -1) 								/* 如果套接字绑定失败，输出错误信息并退出 */
  {
    printf("套接字绑定失败。\n");
    exit(1);
  }
  /* 将套接字设为监听模式，以等待连接请求 */
  ret = listen(sockfd, BACKLOG);
  if(ret == -1) {
    perror("设置监听模式失败\n");
    exit(1);
  }
  printf("等待客户端连接...\n ");
  /* 循环处理客户端的请求 */
  while(1)
  {
    addrlen = sizeof(struct sockaddr_in);
    clientsfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);		/* 接受一个客户端连接 */
    if(clientsfd == -1)
    {
      perror("请求客户端连接错误\n");
      continue;
    }
    pid = fork();					/* 创建子进程 */
    if(pid<0) 						/* 如果进程创建失败，输出错误信息并退出 */
    {
      perror("进程创建失败\n");
      exit(1);
    }
    if(pid==0) 						/* 子进程，处理客户端的请求*/
    {
      close(sockfd);					/* 关闭父进程的套接字 */
      printf("客户端IP： %s\n", inet_ntoa(client_addr.sin_addr));		/* 输出客户端IP地址 */
      /* 获取处理器信息 */
      get_cpu_status(&cpu_stat);
      size  = sizeof(struct cpustatus);
      memcpy(buf, &cpu_stat, size);
      /* 获取内存信息 */
      get_mem_info(&mem_info);
      memcpy(buf+size, &mem_info, sizeof(struct meminfo));
      /* 发送数据 */
      cnt = send(clientsfd, buf, BUF_SIZE, 0);
      if(cnt == -1)
      {
        perror("发送错误\n");
        exit(1);
      }
      printf("操作完成！\n"); 			/* 程序测试使用 */
      close(clientsfd);				/* 关闭当前客户端连接 */
      exit(0); 						/* 子进程退出 */
    }
    close(clientsfd);					/* 父进程，关闭子进程的套接字，准备接受下一个客户端连接 */
  }
  return 0;
}

void get_cpu_status(struct cpustatus *cpu_stat)
{
  long total;
  float user, nice, system, idle;
  long cpu[21];
  char text[201];
  FILE *fp;
  fp = fopen("/proc/stat", "r");			/* 如果/proc/stat文件 */
  if (fp == NULL) 					/* 如果文件打开失败，输出错误信息并退出 */
  {
    printf("打开CPU状态文件失败。\n");
    exit(1);
  }
  while(fgets(text, 200, fp) != NULL) 	/* 提取处理器信息 */
  {
    if(strstr(text, "cpu"))
    {
      sscanf(text, "%ld %f %f %f %f", cpu, &user, &nice, &system, &idle);
    }
  }
  fclose(fp); 						/* 关闭文件 */
  /* 进行各类CPU时间计算 */
  total = user + nice + system + idle;
  user = (user / total) * 100;
  nice = (nice / total) * 100;
  system = (system / total) * 100;
  idle = (idle / total) * 100;
  /* 对结构体各成员进行赋值 */
  cpu_stat->total = total;
  cpu_stat->user = user;
  cpu_stat->nice = nice;
  cpu_stat->system = system;
  cpu_stat->idle = idle;
  return;
}

void get_mem_info(struct meminfo *minfo)
{
  int i, j;
  char total[MEM_SIZE];
  char free[MEM_SIZE];
  char temp[MEM_SIZE*2];
  FILE *fp;
  fp = fopen("/proc/meminfo", "r");		/* 如果/proc/meminfo文件 */
  if (fp == NULL) 					/* 如果文件打开失败，输出错误信息并退出 */
  {
    printf("打开内存信息文件失败。\n");
    exit(1);
  }
  fgets(temp, MEM_SIZE*2, fp);
  strcpy(total, temp); 				/* 系统的总内存空间信息（字符串） */
  fgets(temp, MEM_SIZE*2, fp);
  strcpy(free, temp);			 		/* 系统的空闲内存空间信息（字符串） */
  fclose(fp); 						/* 关闭文件 */
  if(strlen(total) > 0) 				/* 提取总内存空间信息字符串中的数值部分 */
  {
    for(i=0,j=0; i<strlen(total); i++)
    {
      if(isdigit(total[i]))
        minfo->total[j++] = total[i];
    }
    minfo->total[j] = '\0'; 				/* 字符串结束符 */
  }
  if(strlen(free) > 0) 					/* 提取空闲内存空间信息字符串中的数值部分 */
  {
    for(i=0,j=0; i<strlen(free); i++)
    {
      if(isdigit(free[i]))
        minfo->free[j++] = free[i];
    }
    minfo->free[j] = '\0'; 				/* 字符串结束符 */
  }
  return;
}
