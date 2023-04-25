#include <gtk/gtk.h>

// G_GNUC_UNUSED
static void ShowHome(GtkWidget *w, gpointer data) {
    g_print("显示时间 | 进入主页面!");
    g_print("\n");
}

// G_GNUC_UNUSED
static void OpenFile(GtkWidget *w, gpointer data) {
    g_print("显示时间 | 打开选择文件窗口!");
    g_print("\n");
}

static void CloseALL(GtkWidget *win, gpointer data) {
    gtk_widget_destroy(win);
    g_print("显示时间 | 点击了关闭按钮!");
    g_print("\n");
}

static int OpenWindow2(GtkWidget *win, gpointer data);

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *win = NULL;
    win = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(win), "网分界面专用窗口");
    gtk_window_set_default_size(GTK_WINDOW(win), 720, 600);
    g_signal_connect(win, "destroy", G_CALLBACK(CloseALL), NULL);

    gtk_container_set_border_width(GTK_CONTAINER(win), 8);

    // ----------- 布局
    GtkWidget *grid = NULL;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(win), grid);
    /*
        GtkWidget *box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
        gtk_container_add(GTK_CONTAINER(win), box);
    */
    GtkWidget *btnHome = gtk_button_new_with_label("全站工况");
    g_signal_connect(btnHome, "clicked", G_CALLBACK(ShowHome), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnHome, 0, 0, 1, 1);

    GtkWidget *btnImport = gtk_button_new_with_label("文件导入");
    g_signal_connect(btnImport, "clicked", G_CALLBACK(OpenFile), NULL);

    // gtk_container_add(GTK_CONTAINER(box), btnImport);
    gtk_grid_attach(GTK_GRID(grid), btnImport, 1, 0, 1, 1);

    GtkWidget *btnOK = gtk_button_new_with_label("关闭");
    g_signal_connect_swapped(btnOK, "clicked", G_CALLBACK(gtk_widget_destroy),
                             win);
    gtk_grid_attach(GTK_GRID(grid), btnOK, 2, 4, 2, 1);

    btnOK = gtk_button_new_with_label("进入新界面");
    g_signal_connect(btnOK, "clicked", G_CALLBACK(OpenWindow2), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnOK, 2, 5, 2, 1);

    gtk_widget_show_all(win);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    app = gtk_application_new("com.nj-xhp.prs", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = 0;
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

static int OpenWindow2(GtkWidget *win, gpointer data) {
    GtkBuilder *builder = NULL;
    GError *err = NULL;
    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "./cmd/main.ui", &err)) {
        g_printerr("显示时间 | 加载图形界面出错。%s\n", err->message);
        g_clear_error(&err);
        return 1;
    }

    GObject *win2 = NULL;
    win2 = gtk_builder_get_object(builder, "window");
    g_signal_connect(win2, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GObject *btn = NULL;
    btn = gtk_builder_get_object(builder, "button1");
    g_signal_connect(btn, "clicked", G_CALLBACK(ShowHome), NULL);

    btn = gtk_builder_get_object(builder, "button2");
    g_signal_connect(btn, "clicked", G_CALLBACK(OpenFile), NULL);

    // TODO: 点击后这个单个按钮会消失, 整个小窗口没有关闭。
    btn = gtk_builder_get_object(builder, "quit");
    g_signal_connect(btn, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}