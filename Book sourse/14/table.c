/* table.c */
#include <gtk/gtk.h>

void callback1(GtkWidget *widget, gpointer data )		/* 回调函数 */
{
  g_print ("单击按钮1\n");
}

void callback2(GtkWidget *widget, gpointer data )
{
  g_print ("单击按钮2\n");
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  g_print ("删除事件被触发\n");
  gtk_main_quit();
  return FALSE;
}

int main(int argc, char *argv[]) 						/* 主函数 */
{
  GtkWidget *mainwindow; 
  GtkWidget *table;
  GtkWidget *button;
  gtk_init(&argc, &argv); 							/* 初始化 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); 			/* 创建主窗口 */
  /* 为delete_event事件连接一个回调函数 */
  g_signal_connect(mainwindow, "delete_event",
      (GCallback)delete_event, NULL);
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);	/* 设置窗口的边框宽度 */
  /* 创建一个2x2的网格 */
  table = gtk_table_new(2, 2, TRUE);
  gtk_container_add (GTK_CONTAINER (mainwindow), table);			/* 将网格添加到主窗口之中 */
  /* 创建第一个按钮 */
  button = gtk_button_new_with_label("按钮1");
  /* 为clicked信号连接一个回调函数，当按钮被单击时，调用callback1函数 */
  g_signal_connect(button, "clicked", (GCallback)callback1, NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 1, 0, 1); 	/* 将按钮放入网格之中 */
  gtk_widget_show (button);									/* 显示按钮 */
  /* 创建第二个按钮 */
  button = gtk_button_new_with_label("按钮2");
  g_signal_connect(button, "clicked", (GCallback)callback2, NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 1, 2, 0, 1);
  gtk_widget_show (button);
  /* 创建Exit按钮 */
  button = gtk_button_new_with_label("退出");
  g_signal_connect(button, "clicked", (GCallback)delete_event, NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 2, 1, 2);
  gtk_widget_show (button);
  /* 显示网格和窗口 */
  gtk_widget_show(table);
  gtk_widget_show(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
