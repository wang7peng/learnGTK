#include <gtk/gtk.h>

#include "../include/app3.h"

int main(int argc, char **argv) {
    int status = 0;
    status = g_application_run(G_APPLICATION(example_app_new()), argc, argv);

    return status;
}