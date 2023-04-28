#include "../include/app3win.h"

#include <gtk/gtk.h>

#include "../include/app3.h"

struct _ExampleAppWindow {
    GtkApplicationWindow parent;
};

// 私有结构体, 成员是指向 GtkStack 的指针
typedef struct _ExampleAppWindowPrivate {
    GtkWidget *stack;
} ExampleAppWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(ExampleAppWindow, example_app_window,
                           GTK_TYPE_APPLICATION_WINDOW);

static void example_app_window_init(ExampleAppWindow *app) {
    gtk_widget_init_template(GTK_WIDGET(app));
}

static void example_app_window_class_init(ExampleAppWindowClass *class) {
    // 将选定的 ui 文件作为模板, name 必须是绝对路径
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                                "/home/xhp/app3/window.ui");
    // keep a reference to the
    gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class),
                                                 ExampleAppWindow, stack);
}

ExampleAppWindow *example_app_window_new(ExampleApp *app) {
    return g_object_new(EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open(ExampleAppWindow *win, GFile *file) {
    ExampleAppWindowPrivate *priv;
    gchar *basename;
    GtkWidget *scrolled, *view;
    gchar *contents;
    gsize length;

    priv = example_app_window_get_instance_private(win);
    basename = g_file_get_basename(file);

    scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_show(scrolled);
    gtk_widget_set_hexpand(scrolled, TRUE);
    gtk_widget_set_vexpand(scrolled, TRUE);
    view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(view), FALSE);
    gtk_widget_show(view);

    gtk_stack_add_titled(GTK_STACK(priv->stack), scrolled, basename, basename);

    if (g_file_load_contents(file, NULL, &contents, &length, NULL, NULL)) {
        GtkTextBuffer *buffer;

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
        gtk_text_buffer_set_text(buffer, contents, length);
        g_free(contents);
    }

    g_free(basename);
}