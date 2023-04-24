#include <gtk/gtk.h>

GtkWidget *w = NULL;

// 捕捉关闭信号，确保异常关闭都能监控
static gboolean on_delete_event(GtkWidget *w, GdkEvent *e, gpointer data) {
    g_print("delete event occurred!\n");

    // 可选，增加再三确认框
    return TRUE;
}

static void print_hello(GtkWidget *w, GdkEvent *e, gpointer data) {
    g_print("222");
}

void xhpConfWindow() {
    w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(w), "对象配置");
    gtk_window_set_default_size(GTK_WINDOW(w), 720, 480);
    gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(w), 6);
    // 新开窗口不用大小调整
    gtk_window_set_decorated(GTK_WINDOW(w), FALSE);
    gtk_window_set_resizable(GTK_WINDOW(w), FALSE);

    g_signal_connect(w, "delete-event", G_CALLBACK(on_delete_event), NULL);
}

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);
    xhpConfWindow();

    // ----------------------------- 网格布局
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(w), grid);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(grid), box);

    GtkWidget *btn = gtk_button_new_with_label("你好");
    g_signal_connect(btn, "clicked", G_CALLBACK(print_hello), NULL);
    gtk_container_add(GTK_CONTAINER(box), btn);

    GdkPixbuf *logo = gdk_pixbuf_new_from_file_at_scale(
        "/usr/local/etc/xhp.jpg", 28, 28, TRUE, NULL);
    // 信息顺序不用在意，显示时候自动排序
    gtk_show_about_dialog(NULL, "program-name",
                          "PRS-7972B 网络报文记录分析系统", "logo", logo,
                          "copyright", "CYG lnc", "version", "Ver4.2.2", NULL);
    // ----------------------------- 启动
    gtk_widget_show_all(w);
    gtk_main();
    return 0;
}