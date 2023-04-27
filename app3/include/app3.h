#ifndef __APP_3_H
#define __APP_3_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define EXAMPLE_APP_TYPE (example_app_get_type())
G_DECLARE_FINAL_TYPE(ExampleApp, example_app, EXAMPLE, APP, GtkApplication)

extern ExampleApp *example_app_new(void);

G_END_DECLS

#endif