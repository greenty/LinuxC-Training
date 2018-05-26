#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>				/* 包含相关函数头文件 */
#include <errno.h>
#include <string.h>       
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define SERV_PORT 2395			/* 服务器监听端口号 */
#define BUF_SIZE 1024				/* 缓冲区的长度 */
#define MEM_SIZE 32

GtkWidget *entry1;				/* 声明全局GtkWidget类型变量 */
GtkWidget *textview1;	
GtkWidget *button1;

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

void on_button_clicked (GtkButton *button, gpointer user_data)
{
  int ret;
  int sockfd;
  struct sockaddr_in serv_addr;
  char buf[BUF_SIZE];
  struct cpustatus cpu_stat;
  struct meminfo mem_info;
  int i, cnt;
  int size;
  char out[6][MEM_SIZE];					/* 保存输出信息 */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);	/* 创建套接字 */
  if(sockfd == -1)
  {
    printf("创建套接字失败\n");
    exit(1);
  }
  extern GtkWidget *entry1;					/* 声明外部变量 */
  const gchar *entry_text;
  entry_text = gtk_entry_get_text((GtkEntry *)entry1);			/* 从文本输入框中获取要连接的服务器的IP地址 */
  /* 向服务器发出连接请求 */
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);
  serv_addr.sin_addr.s_addr = inet_addr(entry_text);
  bzero(&(serv_addr.sin_zero), 8);
  ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
  if(ret == -1)
  {
    printf("连接错误。\n");
    exit(1);
  }
  /* 接收服务器传来的状态数据 */
  cnt = recv(sockfd, buf, BUF_SIZE, 0);
  if(cnt == -1)
  {
    perror("接收错误\n");
    exit(1);
  }
  /* 提取信息 */
  size  = sizeof(struct cpustatus);
  memcpy(&cpu_stat, buf, size);
  memcpy(&mem_info, buf+size, sizeof(struct meminfo));

  extern GtkWidget *textview1;					/* 声明外部变量 */
  GtkTextBuffer *buffer;
  GtkTextIter start;
  GtkTextIter end;
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (textview1));		/* 获取文本缓冲区  */
  /* 将服务器处理器和内存信息格式化输出到二维数组 */
  sprintf(out[0],"user :\t\t %.2f%%\n", cpu_stat.user);
  sprintf(out[1],"nice :\t\t %.2f%%\n", cpu_stat.nice);
  sprintf(out[2],"system :\t %.2f%%\n", cpu_stat.system);
  sprintf(out[3],"idle :\t\t %.2f%%\n", cpu_stat.idle);
  sprintf(out[4],"total :\t\t %s kB\n",mem_info.total);
  sprintf(out[5],"free :\t\t %s kB \n",mem_info.free);
  gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer),&start,&end);/* 获取开始和结束标记 */
  gtk_text_buffer_delete(GTK_TEXT_BUFFER(buffer),&start,&end);		/* 删除缓冲区中的旧信息 */
  gtk_text_buffer_insert(buffer,&start, "CPU信息\n-------------------------\n", -1);
  for(i=0; i<=5; i++)
  {
    if(i == 3)
    {
      gtk_text_buffer_insert(buffer,&start, "内存信息\n-------------------------\n", -1);
    }
    gtk_text_buffer_insert(buffer,&start, out[i], -1);
  }
  close(sockfd);							/* 关闭套接字 */ 
}

int main(int argc, char *argv[])
{
   gtk_init(&argc, &argv);					/* 初始化GTK+库 */
   GtkBuilder *ui;						/* 声明GtkBuilder类型变量 */
   ui= gtk_builder_new();				/* 初始化GTKBuilder环境 */
   gtk_builder_add_from_file(ui,"serverui.glade",NULL);		/* 读取glade文件 */
   GtkWidget *mainwindow;				/* 声明GtkWidget类型变量 */
   mainwindow= GTK_WIDGET(gtk_builder_get_object(ui,"window1"));     
   entry1= GTK_WIDGET(gtk_builder_get_object(ui,"entry1"));   
   textview1= GTK_WIDGET(gtk_builder_get_object(ui,"textview1"));      
   button1 = GTK_WIDGET(gtk_builder_get_object(ui,"button1"));
   g_signal_connect(button1, "clicked",(GCallback)on_button_clicked, NULL);
   gtk_widget_show(mainwindow);			/* 显示主窗口 */    
   gtk_builder_connect_signals(ui, NULL);	/* 连接GtkBuilder对象所有已定义信号 */
   gtk_main();							/* 开始GTK+主循环 */
   return 0;
}
