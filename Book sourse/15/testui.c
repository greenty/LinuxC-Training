#include <gtk/gtk.h>

void on_button_clicked (GtkButton *button, gpointer user_data)
{
  extern GtkWidget *textview1;					/* 声明外部变量 */
  GtkTextBuffer *buffer;
  
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (textview1));		/* 获取文本缓冲区  */
  GtkTextIter start;
  GtkTextIter end;
  //gtk_text_buffer_set_text (buffer," ",1);
  /* 将服务器处理器和内存信息格式化输出到二维数组 */
  
  gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer),&start,&end);
  gtk_text_buffer_delete(GTK_TEXT_BUFFER(buffer),&start,&end); 
  //gtk_text_view_set_overwrite (GTK_TEXT_VIEW (textview1),TRUE);		/* 设置覆盖模式 */ 
  gtk_text_buffer_insert(buffer,&start,"显示字符串\n", -1);  
}

GtkWidget *textview1;				/* 声明GtkWidget类型变量 */
GtkWidget *button1;
int main(int argc, char *argv[])
{
   gtk_init(&argc, &argv);					/* 初始化GTK+库 */
   GtkBuilder *ui;						/* 声明GtkBuilder类型变量 */
   ui= gtk_builder_new();				/* 初始化GTKBuilder环境 */
   gtk_builder_add_from_file(ui,"ui.glade",NULL);		/* 读取glade文件 */
   GtkWidget *mainwindow;				/* 声明GtkWidget类型变量 */
   mainwindow= GTK_WIDGET(gtk_builder_get_object(ui,"window1"));     
   textview1= GTK_WIDGET(gtk_builder_get_object(ui,"textview1"));      
   button1 = GTK_WIDGET(gtk_builder_get_object(ui,"button1"));
   g_signal_connect(button1, "clicked",(GCallback)on_button_clicked, NULL);
   gtk_widget_show(mainwindow);			/* 显示主窗口 */    
   gtk_builder_connect_signals(ui, NULL);	/* 连接GtkBuilder对象所有已定义信号 */
   gtk_main();							/* 开始GTK+主循环 */
   return 0;
}
