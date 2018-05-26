/* radio.c */
#include <gtk/gtk.h>

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  g_print ("删除事件被触发\n");
  gtk_main_quit();
  return TRUE;
}

int main(int argc, char *argv[]) 						/* 主函数 */
{
  GtkWidget *mainwindow; 
  GtkWidget *vbox;
  GtkWidget *button;
  GSList *group;
  gtk_init(&argc, &argv); 							/* 初始化 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); 			/* 创建主窗口 */
  /* 为delete_event事件连接一个回调函数 */
  g_signal_connect(mainwindow, "delete_event",
      (GCallback)delete_event, NULL);
  gtk_window_set_title(GTK_WINDOW (mainwindow), "复选按钮");			/* 设置窗口的标题 */
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);	/* 设置窗口的边框宽度 */
  /* 创建一个垂直组装盒 */
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(mainwindow), vbox); 			/* 添加到主窗口之中 */
  gtk_widget_show(vbox);
  /* 创建第一个单选按钮 */
  button = gtk_radio_button_new_with_label(NULL, "复选按钮1");
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);		/* 将按钮添加到组装盒之中 */
  gtk_widget_show(button);
  group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));			/* 创建按钮组 */
  /* 创建第二个单选按钮 */
  button = gtk_radio_button_new_with_label(group, "复选按钮2");
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
  gtk_widget_show(button);
  /* 创建第三个单选按钮 */
  button = gtk_radio_button_new_with_label(group, "复选按钮3");
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
  gtk_widget_show(button);
  /* 显示主窗口 */
  gtk_widget_show(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
