/* dialog.c */
#include <gtk/gtk.h>
#define N 64
gint yes(GtkWidget *widget, gpointer data)		/* yes按钮回调函数 */
{
  gtk_main_quit();
  return TRUE;
}

gint no(GtkWidget *widget, gpointer data) 		/* no按钮回调函数 */
{
  gchar text[N];
  static gint i;									/* 纪录按钮按下的次数 */
  i++;
  g_sprintf(text, "“取消”按钮被点击了 %d 次。", i);
  gtk_label_set_text(GTK_LABEL(data), text);			/* 设置标签构件显示的文本 */
  return TRUE;
}

int main(int argc, char **argv) 						/* 主函数 */
{
  GtkWidget *dialog; 
  GtkWidget *label;
  GtkWidget *button;
  GtkWidget *content_area;
  GtkWidget *action_area;
  gtk_init(&argc, &argv); 							/* 初始化 */
  /* 创建对话框 */
  dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW (dialog), "对话框");
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog)); 
  action_area = gtk_dialog_get_action_area (GTK_DIALOG (dialog));
  /* 创建并添加标签构件 */
  label = gtk_label_new("\n你要退出吗？\n");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
  gtk_box_pack_start(							/* 添加到对话框上方的垂直组装盒中 */
      (GtkBox *)content_area, label, TRUE, FALSE, 0);
  /* 创建并添加标签构件 */
  label = gtk_label_new(" ");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_box_pack_start(							/* 添加到对话框上方的垂直组装盒中 */
      (GtkBox *)content_area, label, TRUE, TRUE, 0);
  /* 创建并添加按钮构件 */
  button = gtk_button_new_with_label("确定");
  g_signal_connect(							/* 设置回调函数 */
      button, "clicked", (GCallback)yes, NULL);
  gtk_box_pack_start(							/* 添加到对话框下方的活动区域中 */
      (GtkBox *)action_area, button, TRUE, FALSE, 6);
  /* 创建并添加按钮构件 */
  button = gtk_button_new_with_label("取消");
  g_signal_connect(							/* 设置回调函数 */
      button, "clicked", (GCallback)no, label);
  gtk_box_pack_start(							/* 添加到对话框下方的活动区域中 */
      (GtkBox *)action_area, button, TRUE, FALSE, 6);
  /* 显示所有构件 */
  gtk_widget_show_all(dialog);
  /* 事件循环 */
  gtk_main();
  return 0;
}
