#ifndef __APP_3_H
#define __APP_3_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

// 先是类似名称空间，再加 TYPE，再加 实际类名
#define EXAMPLE_TYPE_APP (example_app_get_type())

G_DECLARE_FINAL_TYPE(ExampleApp, example_app, EXAMPLE, APP, GtkApplication)

extern ExampleApp *example_app_new(void);

G_END_DECLS

#endif