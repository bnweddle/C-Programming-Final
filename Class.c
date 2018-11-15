//
//  Class.c
//  Created by Ahmed Alkhraissi on 11/9/18.

#include "Class.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "Exam.c"

Class* showAllClasses(){

    FILE* fp;

    int  num = 0;
    int id = 0;

    fp = fopen("Classes.txt", "r");
    fscanf(fp, "%d\n", &num);

    Class * c = malloc(num*sizeof(Class));
    c->num = num;
   
    char line[20];
    for(int i = 0; i < num; i++){
       if(fgets(line, 20, fp)!=NULL){
        char * token = strtok(line, ",");
	c[i].id = atoi(token);
        
        token = strtok(NULL, ","); // token = CIS308
	c[i].name = token;
       }
    }
    fclose(fp);
    return c;
}

int main(int argc, char *argv[]) {

// Class * classes = showAllClasses();
  char * name = getClassName("exam308.txt");
  printf("%s", name);
/*
  for (int i = 0; i < 2; i++) {
	printf("%s\n", classes[i].name);
	printf("%d\n", classes[i].id);
  }

  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *class1;
  GtkWidget *class2;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 250);
  gtk_window_set_title(GTK_WINDOW(window), "Classes");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  vbox = gtk_vbox_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  class1 = gtk_button_new_with_label(classes[0].name);
  class2 = gtk_button_new_with_label(classes[1].name);

  gtk_box_pack_start(GTK_BOX(vbox), class1, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), class2, TRUE, TRUE, 0);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  gtk_main();
*/
  return 0;
}

// gcc `pkg-config --cflags gtk+-3.0` -o Class Class.c `pkg-config --libs gtk+-3.0`

