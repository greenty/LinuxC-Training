/*hello.c */
#include <gtk-3.0/gtk/gtk.h>
void hello(GtkWidget *widget, gpointer data )		/* 回调函数 */
{
  g_print ("你好！\n");
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  g_print ("删除事件被触发。\n");
  return FALSE;
}

void destroy(GtkWidget *widget, gpointer data )
{
  gtk_main_quit();
}

int main(int argc, char *argv[]) 					/* 主函数 */
{
  GtkWidget *mainwindow; 
  GtkWidget *button;
  gtk_init(&argc, &argv); 						/* 初始化 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); 			/* 创建主窗口 */
  /* 给delete_event事件连接一个回调函数
  * 用鼠标单击窗口标题条的“×”按钮，或按下Alt+F4时，窗口管理程序会产生该事件 */
  g_signal_connect(mainwindow, "delete_event",
      (GCallback)delete_event, NULL);
  /* 给destroy信号连接一个回调函数
  * 如果delete_event事件的回调函数返回FALSE，产生该信号 */
  g_signal_connect(mainwindow, "destroy",
      (GCallback)destroy, NULL);
  /* 设置窗口的边框宽度 */
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 50);
  /* 创建一个按钮 */
  button = gtk_button_new_with_label("你好");
  /* 给clicked信号连接一个回调函数
  * 当按钮收到clicked信号时，会调用hello函数 */
  g_signal_connect(button, "clicked", (GCallback)hello, NULL);
  /* 将按钮添加到窗口之中 */
  gtk_container_add(GTK_CONTAINER(mainwindow), button);
  /* 显示窗口和按钮 */
  gtk_widget_show(button);
  gtk_widget_show(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
