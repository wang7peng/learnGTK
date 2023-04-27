#include "../include/app3win.h"

#include <gtk/gtk.h>

#include "../include/app3.h"

struct _ExampleAppWindow {
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(ExampleAppWindow, example_app_window,
              GTK_TYPE_APPLICATION_WINDOW);

static void example_app_window_init(ExampleAppWindow *app) {
    gtk_widget_init_template(GTK_WIDGET(app));
}

static void example_app_window_class_init(ExampleAppWindowClass *class) {
    // 将选定的 ui 文件作为模板, name 必须是绝对路径
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                                "/home/xhp/app3/window.ui");
}

ExampleAppWindow *example_app_window_new(ExampleApp *app) {
    return g_object_new(EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open(ExampleAppWindow *win, GFile *file) {}