#include <gtk/gtk.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);
    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "关于");
    gtk_window_set_default_size(GTK_WINDOW(window), 560, 420);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    // gtk_window_maximize(GTK_WINDOW(window));
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);  // fixed when false

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* box;
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    //////////////////////////////////////////// 增加两个按钮
    GtkWidget* button1 = NULL;
    button1 = gtk_button_new_with_label("button1");
    gtk_widget_set_size_request(GTK_WIDGET(button1), 100, 50);
    GtkWidget* button2 = NULL;
    button2 = gtk_button_new_with_label("button2");
    gtk_widget_set_size_request(GTK_WIDGET(button2), 100, 50);

    gtk_container_add(GTK_CONTAINER(window), box);

    // 参数3 TRUE 排列方向上拉伸可变形
    gtk_box_pack_start(GTK_BOX(box), button1, TRUE, FALSE, 50);
    gtk_box_pack_start(GTK_BOX(box), button2, TRUE, FALSE, 50);

    //////////////////////////////////////////// 开启
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

/*
// static 作用域仅限于本文件，防止同名冲突
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *w;
    w = gtk_application_window_new(app);
    gtk_widget_show_all(w);
    g_print("hello world");
}

int main(int argc, int **argv) {
    GtkApplication *app;
    int ret;
    app = gtk_application_new("xhp.com", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    ret = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return ret;
}
*/