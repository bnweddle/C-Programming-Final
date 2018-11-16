//
//  Class.c
//  Created by Ahmed Alkhraissi on 11/9/18.

#include "Class.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

Class * showAllClasses(){
//This finally works!!
    FILE* fp;

    int  num = 0;
   
    fp = fopen("Classes.txt", "r");
    fscanf(fp, "%d\n", &num);

    Class * c = malloc(num*sizeof(Class));
    c->num = num;
   
    char line[20];
    for(int i = 0; i < num; i++){
       if(fgets(line, 20, fp)!=NULL){
        char * token = strtok(line, ",");
	c[i].id = atoi(strdup(token));
 
        token = strtok(NULL, ","); // token = CIS308
	c[i].name = strdup(token);
       }
    }
    fclose(fp);
    printf("%s\n", c[0].name);
    printf("%d\n", c[0].id);
    printf("%s\n", c[1].name);
    printf("%d\n", c[1].id);

    return c;
}

int main(int argc, char *argv[]) {

  Class * classes = showAllClasses();
 // gcc `pkg-config --cflags gtk+-3.0` -o Class Class.c `pkg-config --libs gtk+-3.0`

 
/*  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi;
  GtkWidget *openMi;
  GtkWidget *quitMi;

  GtkWidget *sep;

  GtkAccelGroup *accel_group = NULL;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_window_set_title(GTK_WINDOW(window), "Open File Menu");

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  menubar = gtk_menu_bar_new();
  fileMenu = gtk_menu_new();

  accel_group = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

  fileMi = gtk_menu_item_new_with_mnemonic("_File");
  openMi = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
  sep = gtk_separator_menu_item_new();
  quitMi = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);

  gtk_widget_add_accelerator(quitMi, "activate", accel_group, 
      GDK_OK, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  g_signal_connect(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(quitMi), "activate",
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();
*/
   return 0;
}


void Label(){

/*//This code makes a label
   GtkWidget *window;
  GtkWidget *label;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Label Example");
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);

  label = gtk_label_new("This is a label example");

  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_container_add(GTK_CONTAINER(window), label);

  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();*/
}
