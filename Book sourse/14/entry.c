/* entry.c */
#include <gtk/gtk.h>
void enter(GtkWidget *widget, gpointer data)		/* 文本输入构件回调函数 */
{
  const gchar *text;
  text = gtk_entry_get_text(GTK_ENTRY(widget));
  printf("输入的字符是： %s\n", text);
}

void edit_enable(GtkWidget *widget, GtkWidget *entry) 	/* 复选框回调函数 */
{
   if(gtk_editable_get_editable ((GtkEditable *)entry)==TRUE)
  	gtk_editable_set_editable((GtkEditable *)entry,FALSE);
   else
    gtk_editable_set_editable((GtkEditable *)entry,TRUE);
}

gint delete_event(GtkWidget *widget, 					/* 退出按钮回调函数 */
      GdkEvent *event, gpointer data)
{
  gtk_main_quit();
  return FALSE;
}

int main(int argc, char **argv) 							/* 主函数 */
{
  GtkWidget *mainwindow; 
  GtkWidget *vbox, *hbox;
  GtkWidget *entry; 
  GtkWidget *checkbut;
  GtkWidget *button;
  gtk_init(&argc, &argv); 								/* 初始化 */
  /* 创建主窗口 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(mainwindow, "destroy",
      (GCallback)gtk_main_quit, NULL);
  gtk_window_set_title(GTK_WINDOW (mainwindow), "文本输入构件");
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);
  /* 创建一个垂直组装盒 */
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(mainwindow), vbox);
  /* 创建一个文本输入构件 */
  entry = gtk_entry_new();
  g_signal_connect(entry, "activate",
      (GCallback)enter, NULL);
  gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);
  /* 创建一个水平组装盒 */
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add(GTK_CONTAINER(vbox), hbox);
  /* 创建一个复选按钮 */
  checkbut = gtk_check_button_new_with_label("允许编辑");
  g_signal_connect(checkbut, "toggled",
      (GCallback)edit_enable, entry);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbut), TRUE);
  gtk_box_pack_start(GTK_BOX(hbox), checkbut, TRUE, TRUE, 0);
  /* 创建退出按钮 */
  button = gtk_button_new_with_label("退出");
  g_signal_connect(button, "clicked",
       (GCallback)delete_event, NULL);
  gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
  /* 显示所有构件 */
  gtk_widget_show_all(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
