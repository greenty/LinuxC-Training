#include <gtk/gtk.h>
void on_button1_clicked(GtkButton *button,gpointer user_data)
{
  g_print("按钮被点击了。\n");				/* 按钮的回调函数 */
}

int main(int argc, char *argv[])
{
   gtk_init(&argc, &argv);					/* 初始化GTK+库 */
   GtkBuilder *ui;						/* 声明GtkBuilder类型变量 */
   ui= gtk_builder_new();				/* 初始化GTKBuilder环境 */
   gtk_builder_add_from_file(ui,"glade.glade",NULL);		/* 读取glade文件 */
   GtkWidget *mainwindow;				/* 声明GtkWidget类型变量 */
   mainwindow= GTK_WIDGET(gtk_builder_get_object(ui,"window1"));
   gtk_widget_show(mainwindow);			/* 显示主窗口 */
   GtkWidget *button;
   button = GTK_WIDGET(gtk_builder_get_object(ui,"button1"));
   gtk_widget_show(button);				/* 显示按钮 */
   gtk_builder_connect_signals(ui, NULL);	/* 连接GtkBuilder对象所有已定义信号 */
   gtk_main();							/* 开始GTK+主循环 */
   return 0;
}
