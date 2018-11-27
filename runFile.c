//
//  runFile.c
//  File contain main function
//

#include "Class.c"
#include "Exam.c"
#include "Student.c"
#include <stdio.h>
#include <gtk/gtk.h>

static char * statusMSG = NULL;

static void open_dialog(GtkWidget* button, gpointer window)
{
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Chosse a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
    gtk_widget_show_all(dialog);
    //gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),"/Users/aalkhraissi/Desktop/CIS308/C-Programming-Final/");
    
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp == GTK_RESPONSE_OK)
    {
        char * fn = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        
        GtkWidget *window2;
        GtkWidget *vbox2;
        GtkWidget *grid;
        
        window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window2), 250, 10);
        gtk_window_set_resizable(window2, FALSE);
        
        vbox2 = gtk_vbox_new(5,10);
        grid = gtk_grid_new();
        gtk_box_pack_start(GTK_BOX(vbox2), grid, 10, 10, 10);
        
        Class * classes = showAllClasses();
        Student * students = getStudentInfo();
        
        //Get Exam information
        Exam * exam = getExamInfo(fn);
        
        char * class = assignName(classes, exam->cID);
        Student * studentExam = getStudentAnswers(fn);
        Student * namesS = assignNames(students, studentExam);
        Student * grades = assignGrade(exam, namesS, studentExam);
        statusMSG = g_strdup_printf("Class Name : %s", class);
        
        gtk_window_set_title(GTK_WINDOW(window2), statusMSG);
        
        GtkWidget *label[exam->numOfS];
        for(int i = 0; i < exam->numOfS; i++)
        {
            char * str = g_strdup_printf("\nNAME: %sANSWERS: %sGRADE: %c\n",namesS[i].name, studentExam[i].answers, grades[i].grade);
            label[i] = gtk_label_new(str);
            
            gtk_grid_attach(GTK_GRID (grid), label[i], 0, i, 1, 1);
        }
        gtk_container_add(GTK_CONTAINER(window2), vbox2);
        
        free (classes);
        free (students);
        free (exam);
        
        gtk_widget_show_all(window2);
    }
    else
        statusMSG = g_strdup_printf("Error : Cancel Pressed !!");
        //g_print("You pressed Cancel\n");
    gtk_widget_destroy(dialog);
}

void button_pressed(GtkWidget *widget, gpointer window)
{
    gchar *str = g_strdup_printf("%s", statusMSG);
    gtk_statusbar_push(GTK_STATUSBAR(window),
                       gtk_statusbar_get_context_id(GTK_STATUSBAR(window), str), str);
    g_free(str);
}

int main (int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *vbox;
    
    GtkWidget *toolbar;
    GtkToolItem *openTb;
    GtkToolItem *sep;
    GtkToolItem *exitTb;
    
    GtkWidget *statusbar;
    
    gtk_init(&argc, &argv);
    
    //window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 10);
    gtk_window_set_title(GTK_WINDOW(window), "Grading System");
    gtk_window_set_resizable(window, FALSE);
    
    vbox = gtk_vbox_new(10,0);
    
    toolbar = gtk_toolbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, 0, 0, 0);
    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), statusbar, 0, 0, 0);
    
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
    
    openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);
    
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);
    
    exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);
    
    g_signal_connect(G_OBJECT(openTb), "clicked",
                     G_CALLBACK(open_dialog), window);
    /*
    g_signal_connect(G_OBJECT(openTb), "clicked",
                     G_CALLBACK(button_pressed), G_OBJECT(statusbar));
    */
    g_signal_connect(G_OBJECT(exitTb), "clicked",
                     G_CALLBACK(gtk_main_quit), NULL);
    
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all (window);
    
    gtk_main();
    
    return 0;
}
