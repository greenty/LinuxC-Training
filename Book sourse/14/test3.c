#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <sys/stat.h>   //有关文件的信息
#include <unistd.h>
#include <vte/vte.h>

GtkWidget *textView;     //文本域
static GtkTextBuffer *buffer;    //文本缓冲区
GtkWidget *terminal;      //虚拟终端

void open_file(gpointer data){
    FILE *file;
    GtkTextIter iter;
    GtkTextIter start,end;
    gsize bytes_read;
    gchar *sbuf,*dbuf;          //源缓冲区,目的缓冲区
    gsize dlong;               //转换后的长度
    gsize length;              //文件长度
    struct stat pstat;  
    if(stat("tmp",&pstat)==-1){       //取文件出错
        g_print("OPEN FILE ERROR HERE.......\n");
        return ;
    } 
    length=pstat.st_size;                   //取文件的长度
    sbuf=g_malloc(length);               //分配内存 
    gtk_text_buffer_get_start_iter(buffer,&start);    //取输入域开始点
    gtk_text_buffer_get_end_iter(buffer,&end);     
    gtk_text_buffer_delete(buffer,&start,&end);
    gtk_text_buffer_get_iter_at_line_index(buffer,&iter,0,0);  //取标记
    file=fopen("tmp","r");     //打开文件
    if(file==NULL){
        g_print("ERROR:file can't open.\n");
        g_free(sbuf);
        return;
    }
    bytes_read=fread(sbuf,sizeof(gchar),length,file);     //读文件
    if(g_utf8_validate(sbuf,bytes_read,NULL)==FALSE){           //转换格式，传后指针为dbuf
        dbuf=g_locale_to_utf8(sbuf,length,NULL,&dlong,NULL);
        if(bytes_read==length){
            gtk_text_buffer_insert(buffer,&iter,dbuf,dlong);        
            }              
        }else{
            if(bytes_read==length){
                gtk_text_buffer_insert(buffer,&iter,sbuf,length);       
             }
        }
        if(ferror(file)){
            fclose(file);
            g_free(sbuf);
            return ;        
        }
        fclose(file);
        g_free(sbuf);
        //window＝gtk_widget_get_tiplevel(GTK_WIDGET(data));      
}

void enter_callback( GtkWidget *widget,
                     GtkWidget *entry )
{
  const gchar *entry_text;
  gchar *des="./libmrss-0.19.2/test/./parser ";
  buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW (textView));        //获取文本域
  entry_text=gtk_entry_get_text(GTK_ENTRY(entry));                           //获取输入文本的内容
   des=g_strconcat(g_strconcat(des,entry_text,NULL)," >tmp",NULL);   //拼接
   system(des);     //http://rss.sina.com.cn/roll/sports/hot_roll.xml 
   open_file((gpointer)entry); 
   system("rm ./tmp");   //删除临时文件   
}


void entry_toggle_editable( GtkWidget *checkbutton,
                            GtkWidget *entry )
{
  gtk_editable_set_editable (GTK_EDITABLE (entry),
                             GTK_TOGGLE_BUTTON (checkbutton)->active);
}

void entry_toggle_visibility( GtkWidget *checkbutton,
                              GtkWidget *entry )
{
  gtk_entry_set_visibility (GTK_ENTRY (entry),
			    GTK_TOGGLE_BUTTON (checkbutton)->active);
}
GtkWidget *create_list( void )
{
 
    GtkWidget *scrolled_window;
    GtkWidget *tree_view;
    GtkListStore *model;
    GtkTreeIter iter;
    GtkCellRenderer *cell;
    GtkTreeViewColumn *column;
 
    int i;
  
    /* 创建一个新的滚动窗口(scrolled window)，只有需要时，滚动条才出现 */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                                GTK_POLICY_AUTOMATIC,
                                GTK_POLICY_AUTOMATIC);
  
    model = gtk_list_store_new (1, G_TYPE_STRING);
    tree_view = gtk_tree_view_new ();
    gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_window),
                                           tree_view);
    gtk_tree_view_set_model (GTK_TREE_VIEW (tree_view), GTK_TREE_MODEL (model));
    gtk_widget_show (tree_view);
  
    /* 在窗口中添加一些消息 */
    for (i = 0; i < 10; i++) {
        gchar *msg = g_strdup_printf ("Message #%d", i);
        gtk_list_store_append (GTK_LIST_STORE (model), &iter);
        gtk_list_store_set (GTK_LIST_STORE (model),&iter,0, msg,-1);
        g_free (msg);
    }
  
    cell = gtk_cell_renderer_text_new ();
 
    column = gtk_tree_view_column_new_with_attributes ("Messages",
                                                       cell,
                                                       "text", 0,
                                                       NULL);
 
    gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
                            GTK_TREE_VIEW_COLUMN (column));
 
    return scrolled_window;
}
//修改内容
GtkWidget* create_arrow_button(GtkArrowType arrowtype,GtkShadowType shadowtype)
{
   GtkWidget* button;
   GtkWidget* arrow;
   button = gtk_button_new();
   arrow = gtk_arrow_new(arrowtype,shadowtype);
   gtk_container_add(GTK_CONTAINER(button),arrow);
   gtk_widget_show(arrow);
   return button;
}

GtkWidget *create_frame( void )
{

    GtkWidget *scrolled_window;
    GtkWidget *vbox, *hbox;
    GtkWidget *entry;
   // GtkWidget *button;
    GtkWidget *arrow;
    GtkWidget *check;
    GtkWidget *textview;     //文本域
    GtkWidget *scroll;           //滚动条
    gint tmp_pos;

   scrolled_window = gtk_scrolled_window_new (NULL, NULL);
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                             GTK_POLICY_AUTOMATIC,
                               GTK_POLICY_AUTOMATIC);
 


    vbox = gtk_vbox_new (TRUE,3);  //创建一个新的纵向盒
    gtk_container_add (GTK_CONTAINER (scrolled_window),vbox);
    gtk_widget_show (vbox);
    
    hbox=gtk_hbox_new(FALSE,0);
    gtk_container_add (GTK_CONTAINER (vbox),hbox);
    gtk_widget_show(hbox);
	   
    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);
    g_signal_connect (G_OBJECT (entry), "activate",
		      G_CALLBACK (enter_callback),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "hello");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), " world", -1, &tmp_pos);


   //这个常在为文本输入构件设置了一个缺省值时使用，以方便用户删除它。 
   gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    //Adds child to box, packed with reference to the start of box. 
    //The child is packed after any other child packed with reference to the start of box.
    gtk_box_pack_start (GTK_BOX (hbox), entry, TRUE, TRUE, 0);
    gtk_widget_show (entry);
 
    //创建确认按钮
    //button=gtk_button_new_with_label("sumbit");
    arrow = create_arrow_button(GTK_ARROW_RIGHT,GTK_SHADOW_IN);
    gtk_box_pack_start(GTK_BOX(hbox),arrow,FALSE,TRUE,0);
    g_signal_connect(G_OBJECT(arrow),"clicked",G_CALLBACK(enter_callback),entry);
    gtk_widget_show(arrow);
 /*    
    //创建新的滚动条
    scroll=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll)
    ,GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox),scroll,TRUE,TRUE,0);
    gtk_widget_show(scroll);
*/
     //文本域
    //创建新的滚动条
    scroll=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll)
    ,GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox),scroll,TRUE,TRUE,0);
    gtk_widget_show(scroll);

     //文本域
    textView=gtk_text_view_new();
   gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW   (scroll),textView);
    gtk_widget_show(textView);

    gtk_widget_show_all (scrolled_window);
    return scrolled_window;
}

int main( int  argc,char *argv[] )
{

    GtkWidget *window;
    GtkWidget *hpaned;
    GtkWidget *vbox, *hbox;
    GtkWidget *entry;
   // GtkWidget *button;
    GtkWidget *arrow;
    GtkWidget *check;
    //GtkWidget *textView;     //文本域
    GtkWidget *scroll;           //滚动条
    GtkWidget *frame;
    GtkWidget *list;
    gint tmp_pos;

    gtk_init (&argc, &argv);

    /* 创建一个新窗口 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window),400, 200);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");


    /* 当窗口收到 "delete_event" 信号 (这个信号由窗口管理器发出，通常是“关闭”
     * 选项或是标题栏上的关闭按钮发出的)，我们让它调用在前面定义的 delete_event() 函数。
     * 传给回调函数的 data 参数值是 NULL，它会被回调函数忽略。
    g_signal_connect (G_OBJECT (window), "delete_event",
		      G_CALLBACK (delete_event), NULL);*/

    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);

    /* 当点击按钮时，会通过调用 gtk_widget_destroy(window) 来关闭窗口。
     * "destroy" 信号会从这里或从窗口管理器发出。*/

    g_signal_connect_swapped (G_OBJECT (window), "delete_event",
                              G_CALLBACK (gtk_widget_destroy), 
                              window);
    hpaned=gtk_hpaned_new();/*创建横向分栏窗口构件*/
    gtk_container_add(GTK_CONTAINER(window),hpaned);/*将分栏窗口构件加入窗体*/
  //  gtk_paned_set_handle_size(GTK_PANED(hpaned),10);
    gtk_paned_set_gutter_size(GTK_PANED(hpaned),15);
    gtk_widget_show(hpaned);

   list = create_list();
   gtk_paned_add1 (GTK_PANED(hpaned),list);
    gtk_widget_show(list);

  frame = create_frame();
  gtk_paned_add2 (GTK_PANED(hpaned),frame);
  gtk_widget_show(frame);

   
    
    gtk_widget_show_all (window);

    gtk_main();

    return 0;
}
