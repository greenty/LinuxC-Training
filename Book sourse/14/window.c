/* window.c */
#include<gtk/gtk.h>					/* 包含了GTK+编程中所有需要的头文件 */
int main(int argc, char *argv[])
{
  GtkWidget *win;				/* 定义主窗口对象 */
  gtk_init(&argc, &argv);				/* 初始化 */
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);		/* 创建窗口，大小为200x200 */
  gtk_widget_show(win); 			/* 显示窗口 */
  gtk_main();						/* 主循环 */
  return 0;
}
