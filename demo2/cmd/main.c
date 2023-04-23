#include <gtk-3.0/gtk/gtk.h>

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);

    // ----------------------------------- 设置顶级窗口
    GtkWidget *window = NULL;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "网络报文分析系统");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // ----------------------------------- 固定布局
    GtkWidget *fixed;
    fixed = gtk_fixed_new();

    GtkWidget *buttonHome = NULL;
    buttonHome = gtk_button_new_with_label("全站工况");
    gtk_fixed_put(GTK_FIXED(fixed), buttonHome, 5, 35);

    GtkWidget *buttonMonitor = NULL;
    buttonMonitor = gtk_button_new_with_label("实时监视");
    gtk_fixed_put(GTK_FIXED(fixed), buttonMonitor, 105, 35);

    GtkWidget *buttonQuery = NULL;
    buttonQuery = gtk_button_new_with_label("查询统计");
    gtk_fixed_put(GTK_FIXED(fixed), buttonQuery, 205, 35);

    GtkWidget *btnYes = NULL;
    btnYes = gtk_button_new_with_label("确定");
    gtk_fixed_put(GTK_FIXED(fixed), btnYes, 520, 420);
    g_signal_connect(btnYes, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *labelStartTime = NULL;
    labelStartTime = gtk_label_new_with_mnemonic("开始时间");
    gtk_fixed_put(GTK_FIXED(fixed), labelStartTime, 20, 100);

    GtkWidget *entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), entry1, 100, 100);

    GtkWidget *labelEndTime = NULL;
    labelEndTime = gtk_label_new_with_mnemonic("结束时间");
    gtk_fixed_put(GTK_FIXED(fixed), labelEndTime, 320, 100);

    GtkWidget *entry2 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), entry2, 400, 100);

    /******** 测试fix move 位置更新功能*********/
    GtkWidget *button1 = NULL;
    button1 = gtk_button_new_with_label("button1");
    gtk_fixed_put(GTK_FIXED(fixed), button1, 20, 250);

    // 位置更新
    gtk_fixed_move(GTK_FIXED(fixed), button1, 420, 350);

    gtk_container_add(GTK_CONTAINER(window), fixed);

    // ----------------------------------- 启动
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}