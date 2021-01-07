#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkBuilder      *builder; 
    GtkWidget       *window;
    GError *err = NULL;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new(); 
    gchar *my_glade_file = 
    "<interface>"
        "<requires lib=\"gtk+\" version=\"3.24\"/>"
            "<object class=\"GtkApplicationWindow\" id=\"window_main\">"
                "<property name=\"can-focus\">False</property>"
                "<property name=\"title\" translatable=\"yes\">Application</property>"
                "<property name=\"default-width\">440</property>"
                "<property name=\"default-height\">250</property>"
                "<property name=\"icon\">logo.svg</property>"
                "<property name=\"has-resize-grip\">True</property>"
                "<property name=\"show-menubar\">False</property>"
                "<signal name=\"destroy\" handler=\"on_window_main_destroy\" swapped=\"no\"/>"
                "<child>"
                  "<object class=\"GtkLinkButton\" id=\"gtk_link\">"
                    "<property name=\"label\" translatable=\"yes\">Կարճ ինֆո</property>"
                    "<property name=\"name\">gtk_link</property>"
                    "<property name=\"width-request\">10</property>"
                    "<property name=\"height-request\">10</property>"
                    "<property name=\"visible\">True</property>"
                    "<property name=\"can-focus\">True</property>"
                    "<property name=\"focus-on-click\">False</property>"
                    "<property name=\"receives-default\">True</property>"
                    "<property name=\"tooltip-markup\" translatable=\"yes\"></property>"
                    "<property name=\"halign\">center</property>"
                    "<property name=\"valign\">center</property>"
                    "<property name=\"hexpand\">True</property>"
                    "<property name=\"vexpand\">True</property>"
                    "<property name=\"relief\">none</property>"
                    "<property name=\"use-underline\">True</property>"
                    "<property name=\"uri\">https://myinfo.netlify.app</property>"
                  "</object>"
                "</child>"
            "</object>"
    "</interface>";
    gchar *ids[2] = {
        "window_main",
        "gtk_link"
    };
    gtk_builder_add_objects_from_string (builder, my_glade_file, -1, ids, &err);

    if(0 == gtk_builder_add_from_string (builder, my_glade_file, -1, &err)) {
      fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
    }

    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    if (NULL == window) {
        /* Print out the error. You can use GLib's message logging  */
        fprintf(stderr, "Unable to file object with id \"window_main\" \n");
        /* Your error handling code goes here */
    }
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}