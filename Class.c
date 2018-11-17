//
//  Class.c
//  Created by Ahmed Alkhraissi on 11/9/18.

#include "Exam.c"
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
    return c;
}

int main(int argc, char *argv[]) {
//Testing Methods:

  Class * classes = showAllClasses();
  Student * students = getStudentInfo();
  Exam * exam1 = getExamInfo("exam308.txt");
  Exam * exam2 = getExamInfo("exam450.txt");

  int i;
  for(i=0; i < classes->num; i++){
     printf("%d: %s\n", classes[i].id, classes[i].name);
  }

  for(i=0; i < students->num; i++){
     printf("%d: %s\n", students[i].id, students[i].name);
  }

  printf("NumOfQ: %d NumOfS: %d Answers: %s\n", exam1->numOfQ, exam1->numOfS, exam1->answers);
  printf("NumOfQ: %d NumOfS: %d Answers: %s\n", exam2->numOfQ, exam2->numOfS, exam2->answers);

  Student * studentExam1 = getStudentAnswers("exam308.txt");
  Student * studentExam2 = getStudentAnswers("exam450.txt");

  for(i=0; i < exam1->numOfS; i++){
     printf("Id: %d Answers: %s\n", studentExam1[i].id, studentExam1[i].answers);
  }

  for(i=0; i < exam2->numOfS; i++){
     printf("Id: %d Answers: %s\n", studentExam2[i].id, studentExam2[i].answers);
  }

  double score = computeScore(exam1->answers,studentExam1[0].answers);
  enum grade g = check(score);
  const char c = getGrade(g);
  printf("%c\n", c);

/*  GtkWidget *window;
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
*/   return 0;
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
