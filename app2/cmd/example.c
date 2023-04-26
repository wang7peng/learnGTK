#include "../include/example.h"

#include <gtk/gtk.h>

#include "../include/examplewin.h"

struct _ExampleApp {
    GtkApplication parent;
};

// 前两个参数是两种命名风格，其实是同一个东西
G_DEFINE_TYPE(ExampleApp, example_app, GTK_TYPE_APPLICATION);

/**
 * G_DEFINE_TYPE 自动声明两个函数 xxx_init() 和 xxx_class_init() ,相当于 C++
 * 的构造函数。
 *
 * xxx_init 在每个对象被调用的时候都会被创建， xxx_class_init
 * 只有在第一次创建对象的时候才会被调用。
 */
static void example_app_init(ExampleApp *app) {}

static void example_app_activate(GApplication *app) {
    ExampleAppWindow *win;

    win = example_app_window_new(EXAMPLE_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

static void example_app_open(GApplication *app, GFile **files, gint n_files,
                             const gchar *hint) {
    GList *windows;
    ExampleAppWindow *win;
    int i;

    windows = gtk_application_get_windows(GTK_APPLICATION(app));
    if (windows)
        win = EXAMPLE_APP_WINDOW(windows->data);
    else
        win = example_app_window_new(EXAMPLE_APP(app));

    for (i = 0; i < n_files; i++) example_app_window_open(win, files[i]);

    gtk_window_present(GTK_WINDOW(win));
}

// 重写, 带命令行参数启动时用 open(), 不带命令行参数用 activate()
static void example_app_class_init(ExampleAppClass *class) {
    G_APPLICATION_CLASS(class)->activate = example_app_activate;
    G_APPLICATION_CLASS(class)->open = example_app_open;
}

ExampleApp *example_app_new(void) {
    /**
     * g_object_new 是参数可变, 第一个是对象类型，其他都是对象的属性。
     * 第一个参数必须, 是需要创建的对象的类型。要求这个对象必须是 GObject
     * 的子对象， 这个子对象必须在 glib 自己维护的数据结构中注册
     */
    return g_object_new(EXAMPLE_APP_TYPE, "application-id", "com.xhp.programIM",
                        "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}