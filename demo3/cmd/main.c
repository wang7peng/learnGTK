#include <gtk-3.0/gtk/gtk.h>

GtkWidget *w = NULL;

void xhpTopWindow(GtkWidget *w) {}

int btnOnClicked(GtkWidget *wi, int data) {
    gtk_window_set_title(GTK_WINDOW(w), "新和普电力科技");
    return 1;
}

int btn2OnClicked(GtkWidget *wi, int data) {
    gtk_window_set_title(GTK_WINDOW(w), "网络报文记录分析系统 v0.1");
    return 1;
}

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);

    w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(w), "网络报文记录分析系统");
    gtk_window_set_default_size(GTK_WINDOW(w), 720, 480);
    gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
    gtk_window_set_decorated(GTK_WINDOW(w), TRUE);
    gtk_window_set_resizable(GTK_WINDOW(w), TRUE);
    g_signal_connect(w, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // xhpTopWindow(w);

    // GtkWidget *btnMenu = gtk_menu_button_new();
    GtkWidget *grid = gtk_grid_new();

    GtkWidget *btnHome = gtk_button_new_with_label("全站工况");
    gtk_grid_attach(GTK_GRID(grid), btnHome, 0, 0, 3, 1);

    GtkWidget *btnMonitor = gtk_button_new_with_label("实时监视");
    gtk_grid_attach(GTK_GRID(grid), btnMonitor, 3, 0, 3, 1);

    GtkWidget *btnQuery = gtk_button_new_with_label("查询统计");
    gtk_grid_attach(GTK_GRID(grid), btnQuery, 6, 0, 3, 1);

    GtkWidget *btnRecord = gtk_button_new_with_label("记录文件管理");
    gtk_grid_attach(GTK_GRID(grid), btnRecord, 9, 0, 3, 1);

    GtkWidget *btnUnit = gtk_button_new_with_label("装置信息");
    gtk_grid_attach(GTK_GRID(grid), btnUnit, 12, 0, 3, 1);

    GtkWidget *btnConf = gtk_button_new_with_label("对象配置");
    gtk_grid_attach(GTK_GRID(grid), btnConf, 15, 0, 3, 1);

    // ****** 信号学习
    GtkWidget *btn1 = gtk_button_new_with_label("程序来源");
    gtk_grid_attach(GTK_GRID(grid), btn1, 7, 4, 5, 2);
    g_signal_connect(btn1, "clicked", G_CALLBACK(btnOnClicked), NULL);

    GtkWidget *btn2 = gtk_button_new_with_label("程序名字");
    gtk_grid_attach(GTK_GRID(grid), btn2, 7, 6, 5, 2);
    g_signal_connect(btn2, "clicked", G_CALLBACK(btn2OnClicked), NULL);

    gtk_container_add(GTK_CONTAINER(w), grid);
    // ----------------------------- 启动
    gtk_widget_show_all(w);
    gtk_main();

    return 0;
}