/* labels.c */
#include <gtk/gtk.h>
int main(int argc, char *argv[])
{
  GtkWidget *mainwindow; 
  GtkWidget *vbox;
  GtkWidget *labels;
  gtk_init(&argc, &argv); 							/* 初始化 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); 			/* 创建主窗口 */
  g_signal_connect(mainwindow, "destroy",
      (GCallback)gtk_main_quit, NULL);
  gtk_window_set_title(GTK_WINDOW (mainwindow), "标签");			/* 设置窗口的标题 */
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);	/* 设置窗口的边框宽度 */
  /* 创建一个垂直组装盒 */
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(mainwindow), vbox); 			/* 添加到主窗口之中 */
  /* 创建第一个标签 */
  labels = gtk_label_new("第一行：你好吗？\n第二行：Hello!");
  gtk_label_set_justify(GTK_LABEL(labels), GTK_JUSTIFY_RIGHT);
  gtk_box_pack_start(GTK_BOX(vbox), labels, TRUE, TRUE, 0);
  /* 创建第二个标签 */
  labels = gtk_label_new("第三行：Linux C\n第四行：是最棒的！ ");
  gtk_label_set_justify(GTK_LABEL(labels), GTK_JUSTIFY_LEFT);
  gtk_box_pack_start(GTK_BOX(vbox), labels, TRUE, TRUE, 0);
  /* 显示所有构件 */
  gtk_widget_show_all(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
