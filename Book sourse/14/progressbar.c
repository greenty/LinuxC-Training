/* progressbar.c */
#include <gtk/gtk.h>
gint star; 							/* 状态标志 */
gint pas;
gint progress(gpointer pbar )				/* 更新进度条 */
{
  gdouble i;
  i = gtk_progress_bar_get_fraction(pbar);		/* 获取进度条的当前值 */
  if(0 == star) 					 				/* 判断进度更新是否被停止 */
  {
    if(0 == pas)								 	/* 判断进度更新是否被暂停 */
    {
      i = i + 0.01;
      pas = 0;
    }
  }
  else
  {
    i = 0;										/* 停止状态下将进度条置为0 */
  }  
  gtk_progress_bar_set_fraction(pbar,i);		/* 更新进度条 */ 
  return TRUE ;
}

void show_toggle(GtkWidget *widget, GtkProgressBar *pbar) 		/* 显示文本复选框回调函数 */
{
  if(gtk_progress_bar_get_show_text (pbar)==TRUE)
    gtk_progress_bar_set_show_text (pbar,FALSE);
  else
    gtk_progress_bar_set_show_text (pbar,TRUE);
}

gint start_event(gpointer data, GtkProgressBar *pbar)			/* 开始按钮回调函数 */
{
  star = 0;									/* 设置状态标志*/
  pas = 0;
  return TRUE;
}

gint pause_event(gpointer data, GtkWidget *widget)			/* 暂停按钮回调函数 */
{
  pas = 1;
  return TRUE;
}

gint stop_event(GtkWidget *widget, gpointer data)			/* 停止按钮回调函数 */
{
  star = 1; 										/* 设置状态标志*/
  pas = 1;
  return TRUE;
}

gint delete_event(GtkWidget *widget, 					/* 关闭按钮回调函数 */
    GdkEvent *event, gpointer data)
{
  gtk_main_quit();
  return FALSE;
}

int main(int argc, char *argv[]) 							/* 主函数 */
{
  GtkWidget *mainwindow;
  GtkWidget *vbox, *hbox;
  GtkWidget *pbar;
  GtkWidget *checkbut;
  GtkWidget *button;
  
  gtk_init(&argc, &argv); 								/* 初始化 */
  /* 创建主窗口 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(mainwindow, "destroy",
      (GCallback)gtk_main_quit, NULL);
  gtk_window_set_title(GTK_WINDOW (mainwindow), "进度条");
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);
  /* 创建一个垂直组装盒 */
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(mainwindow), vbox);
  /* 创建进度条构件 */
  pbar = gtk_progress_bar_new();
  g_timeout_add (100, progress, pbar);		/* 对进度条进行连续更新，间隔时间为0.1s */
  gtk_box_pack_start(GTK_BOX(vbox), pbar, TRUE, TRUE, 0);
  /* 创建一个水平组装盒 */
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add(GTK_CONTAINER(vbox), hbox);
  /* 创建显示文本复选按钮 */
  checkbut = gtk_check_button_new_with_label("显示文字");
  g_signal_connect(checkbut, "toggled",
      (GCallback)show_toggle, pbar);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbut), TRUE);
  gtk_box_pack_start(GTK_BOX(hbox), checkbut, TRUE, TRUE, 0);
  /* 创建一个水平组装盒 */
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(vbox), hbox);
  /* 创建开始按钮 */
  button = gtk_button_new_with_label("开始");
  g_signal_connect(button, "clicked",
      (GCallback)start_event, pbar);
  gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
  /* 创建暂停按钮 */
  button = gtk_button_new_with_label("暂停");
  g_signal_connect(button, "clicked",
      (GCallback)pause_event, NULL);
  gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
  /* 创建停止按钮 */
  button = gtk_button_new_with_label("停止");
  g_signal_connect(button, "clicked",
      (GCallback)stop_event, NULL);
  gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
  /* 创建关闭按钮 */
  button = gtk_button_new_with_label("关闭");
  g_signal_connect(button, "clicked",
      (GCallback)delete_event, NULL);
  gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
  /* 显示所有构件 */
  gtk_widget_show_all(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
