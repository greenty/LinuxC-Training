#include <gtk/gtk.h>
gint callback(GtkWidget *widget, gpointer data) 	/* 关于按钮回调函数 */
{
  const gchar *auth[] = {						/* 软件作者信息 */
    "Linux <xxxxxx@kernel.org>",
    "GTK+ <xxxxxx@gnome.org>",
    "GCC <xxxxxx@gnome.org>",
    NULL
  };
  const gchar *doc[] = {					/* 文档作者信息 */
    "Hello C <xxxxxx@gnome.org>",
    NULL
  };
  GdkPixbuf *pix = gdk_pixbuf_new_from_file("1.png",NULL);	/* 载入logo图片 */
  gtk_show_about_dialog (NULL,								/* 设置并输出关于对话框内容 */
  						 "authors",auth,
  						 "documenters",doc,
  						 "version","0.01",
  						 "program-name","我的第一个GTK+程序",
  						 "logo",pix,
  						 "copyright","(C) 2012 the Free Software Foundation",
  						 "comments","这只是一个简单的示例程序",
  						 "wrap-license",FALSE,
  						 NULL);
  return TRUE;
}

gint clo(GtkWidget *widget, gpointer data)	/* 关闭按钮回调函数 */
{
  gtk_main_quit();
  return TRUE;
}


int main(int argc, char **argv) 						/* 主函数 */
{
  GtkWidget *mainwindow;
  GtkWidget *vbox;
  GtkWidget *button;

  gtk_init(&argc, &argv); 							/* 初始化 */
  /* 创建主窗口 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(mainwindow, "destroy",
      (GCallback)gtk_main_quit, NULL);
  gtk_window_set_title((GtkWindow *)mainwindow, "关于对话框");
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);
  /* 创建一个垂直组装盒 */
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(mainwindow), vbox);
  /* 创建关于按钮 */
  button = gtk_button_new_with_label("关于");
  g_signal_connect(button, "clicked",
      (GCallback)callback, NULL);
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
  /* 创建关闭按钮 */
  button = gtk_button_new_with_label("关闭");
  g_signal_connect(button, "clicked",
      (GCallback)clo, NULL);
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
  /* 显示所有构件 */
  gtk_widget_show_all(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
