#ifndef EXAMPLE2_H
#define EXAMPLE2_H

#include <gtk/gtk.h>

#include "example.h"

G_BEGIN_DECLS

#define EXAMPLE_APP_WINDOW_TYPE (example_app_window_get_type())

G_DECLARE_FINAL_TYPE(ExampleAppWindow, example_app_window, EXAMPLE, APP_WINDOW,
                     GtkApplicationWindow)

extern ExampleAppWindow *example_app_window_new(ExampleApp *);

extern void example_app_window_open(ExampleAppWindow *, GFile *);

G_END_DECLS

#endif