#include "examplewin.h"

#include <gtk/gtk.h>

#include "example.h"

struct _ExampleAppWindow {
    GtkApplicationWindow parent;
};

/**
 * 功能: 让 C 能够支持 Gobject 面向对象
 */
G_DEFINE_TYPE(ExampleAppWindow, example_app_window,
              GTK_TYPE_APPLICATION_WINDOW);

static void example_app_window_init(ExampleAppWindow *app) {}

static void example_app_window_class_init(ExampleAppWindowClass *class) {}

ExampleAppWindow *example_app_window_new(ExampleApp *app) {
    return g_object_new(EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open(ExampleAppWindow *win, GFile *file) {}