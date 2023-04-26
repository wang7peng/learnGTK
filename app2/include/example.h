#ifndef __EXAMPLE_H
#define __EXAMPLE_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

/**
 * 在同名头文件 example.c 里必须定义 G_DEFINE_TYPE 宏
 * example_app_get_type() 函数和宏里的 example_app 参数配套。
 * 也就是，这个 example_app_get_type() 是由 G_DEFINE_TYPE 宏自动生成的。
 */
#define EXAMPLE_APP_TYPE (example_app_get_type())
G_DECLARE_FINAL_TYPE(ExampleApp, example_app, EXAMPLE, APP, GtkApplication)

extern ExampleApp *example_app_new(void);

G_END_DECLS

#endif