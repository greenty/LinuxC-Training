/* combo.c */
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#define N 50
typedef struct _Calculate					/* 定义结构体，用来向回调函数传递参数 */
{
  GtkWidget *entry1; 
  GtkWidget *entry2;
  GtkWidget *combo;
  GtkWidget *label;
} Calculate;

gint cal_event(GtkWidget *widget, Calculate *objs)		/* 计算按钮回调函数 */
{
  const gchar *text1, *text2;
  const char *options;
  gchar result[N];
  char operator;
  gint x, y, z; 
  gint flag;
  text1 = gtk_entry_get_text(				/* 获取文本输入构件中的字符串 */
      (GtkEntry *)objs->entry1);
  x = atoi(text1); 						/* 将得到的字符串转换为整数 */
  text2 = gtk_entry_get_text(				/* 获取文本输入构件中的字符串 */
      (GtkEntry *)objs->entry2);
  y = atoi(text2); 						/* 将得到的字符串转换为整数 */
  options = gtk_combo_box_text_get_active_text((GtkComboBoxText *)objs->combo);/* 获取组合框构件中用户选择的字符串 */
  operator=*options; 					/* 提取运算符 */
  flag = 0;								/* 出错标志，用于后面的错误检测 */
  switch (operator)						/* 对两个操作数进行运算 */
  {
    case '+':							/* 加法运算 */
      z = x + y;
      break;
    case '-': 							/* 减法运算 */
      z = x - y;
      break;
    case '*': 							/* 乘法运算 */
      z = x * y;
      break;
    case '/': 							/* 除法运算 */
      if(0 == y)							/* 除数为0时，设置出错标志 */
        flag = 1;
      else
        z = x / y;
      break;
    default: 							/* 其余情况，设置出错标志 */
      flag = 1;
  }
  if(1 == flag) 							/* 检测出错标志 */
    g_sprintf(result, "计算错误");
  else
    g_sprintf(result, "%d", z); 				/* 将运算结果转换为字符串 */
  gtk_label_set_text(GTK_LABEL(objs->label), result);	/* 输出运算结果或出错提示 */
  return TRUE;
}

gint close_event(GtkWidget *widget, 		/* 关闭按钮回调函数 */
    GdkEvent *event, gpointer data)
{
  gtk_main_quit();
  return TRUE;
}

int main(int argc, char **argv) 				/* 主函数 */
{
  Calculate objs;
  GtkWidget *mainwindow;
  GtkWidget *table;
  GtkWidget *label;
  GtkWidget *button;

  gtk_init(&argc, &argv); 					/* 初始化 */
  /* 创建主窗口 */
  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  gtk_window_set_title(GTK_WINDOW (mainwindow), "下拉框");
  gtk_container_set_border_width(GTK_CONTAINER (mainwindow), 15);
  /* 创建一个6x2的网格 */
  table = gtk_table_new(6, 2, TRUE);
  gtk_container_add(					/* 将网格添加到主窗口之中 */
      GTK_CONTAINER (mainwindow), table);
  /* 创建一个文本输入构件，用于操作数输入 */
  objs.entry1 = gtk_entry_new();
  gtk_table_attach_defaults(				/* 将文本输入构件放到网格之中 */
      GTK_TABLE (table), objs.entry1, 0, 2, 0, 1);
  /* 创建一个组合框构件，用于操作符选择 */
  objs.combo = gtk_combo_box_text_new ();
  gtk_combo_box_text_append((GtkComboBoxText *)objs.combo,"+","+");
  gtk_combo_box_text_append((GtkComboBoxText *)objs.combo,"-","-");
  gtk_combo_box_text_append((GtkComboBoxText *)objs.combo,"*","*");
  gtk_combo_box_text_append((GtkComboBoxText *)objs.combo,"/","/");
  gtk_combo_box_text_append((GtkComboBoxText *)objs.combo,"text","请选择运算符");
  gtk_combo_box_set_active_id ((GtkComboBox *)objs.combo,"text");
  gtk_table_attach_defaults (				/* 将组合框构件放到网格之中 */
      GTK_TABLE (table), objs.combo, 0, 2, 1, 2); 
  /* 创建一个文本输入构件，用于操作数输入 */
  objs.entry2 = gtk_entry_new();
  gtk_table_attach_defaults (				/* 将文本输入构件放到网格之中 */
      GTK_TABLE (table),objs.entry2, 0, 2, 2, 3); 
  /* 创建计算按钮 */
  button = gtk_button_new_with_label("计算");
  g_signal_connect(button, "clicked",
      (GCallback)cal_event,&objs);
  gtk_table_attach_defaults (				/* 将按钮构件放到网格之中 */
      GTK_TABLE (table), button, 0, 2, 3, 4); 
  /* 创建一个标签构件 */
  label = gtk_label_new("结果：");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
  gtk_table_attach_defaults (				/* 将标签构件放到网格之中 */
      GTK_TABLE (table), label, 0, 1, 4, 5);
  /* 创建一个标签构件，用于计算结果显示 */
  objs.label = gtk_label_new(" ");
  gtk_label_set_justify(GTK_LABEL(objs.label), GTK_JUSTIFY_CENTER);
  gtk_table_attach_defaults (				/* 将标签构件放到网格之中 */
      GTK_TABLE (table), objs.label, 1, 2, 4, 5); 
  /* 创建关闭按钮 */
  button = gtk_button_new_with_label("关闭");
  g_signal_connect(button, "clicked",
      (GCallback)close_event, NULL);
  gtk_table_attach_defaults (				/* 将按钮构件放到网格之中 */
      GTK_TABLE (table), button, 1, 2, 5, 6); 
  /* 显示所有构件 */
  gtk_widget_show_all(mainwindow);
  /* 事件循环 */
  gtk_main();
  return 0;
}
