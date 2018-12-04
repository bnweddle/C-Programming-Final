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
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),"/Users/aalkhraissi/Desktop/CIS308/C-Programming-Final/");
    
    //gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
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
        
        vbox2 = gtk_vbox_new(0,10);
        grid = gtk_grid_new();
        gtk_box_pack_start(GTK_BOX(vbox2), grid, 10, 10, 10);
        
        Class * classes = getClassesInfo();
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

    gtk_widget_destroy(dialog);
}

/*Callback function in which reacts to the "response" signal. Be sure to place
 it before the function it is called in*/
static void on_response(GtkDialog *dialog, gint response_id, gpointer user_data)
{
    /*For demonstration purposes, this will show the int value
     of the response type*/
    g_print ("response is %d\n", response_id);
    
    /*This will cause the dialog to be destroyed*/
    gtk_widget_destroy (GTK_WIDGET (dialog));
}

/*Callback function in which reacts to the "clicked" signal*/
static void show_dialog(GtkButton *button, gpointer user_data)
{
    GtkWindow *window = user_data;
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;
    
    gint response_id;
    
    /*Create the dialog window. Modal windows prevent interaction with other
     windows in the same application*/
    dialog = gtk_dialog_new_with_buttons("About Project", window, GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_OK, NULL);
    
    /*Create a label and attach it to the content area of the dialog*/
    content_area = gtk_dialog_get_content_area (GTK_DIALOG(dialog));
    label = gtk_label_new("\nCreated By\nAhmed Alkhraissi & Bethany Weddle\n");
    gtk_container_add(GTK_CONTAINER(content_area), label);
    
    /*The main purpose of this is to show dialog's child widget, label*/
    gtk_widget_show_all(dialog);
    
    /*Connecting the "response" signal from the user to the associated
     callback function*/
    g_signal_connect(GTK_DIALOG(dialog), "response", G_CALLBACK (on_response), NULL);
    
}

static void destroy(GtkWidget *widget, gpointer window)
{
    gtk_widget_destroy(window);
}

static void button_student(GtkWidget *widget, gpointer data)
{
    char * student = gtk_entry_get_text(GTK_ENTRY(data));
    if(student != "")
    AddNewStudent(student);
    
    gtk_editable_select_region(GTK_EDITABLE(data), 0,-1); // text from 0 to the end
    gtk_editable_copy_clipboard(GTK_EDITABLE(data));
}

static void add_student(GtkButton *button, gpointer user_data)
{
    GtkWidget *window, *entry, *button2, *vbox;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 10);
    gtk_window_set_title(GTK_WINDOW(window), "Add New Student");
    gtk_window_set_resizable(window, FALSE);
    
    entry = gtk_entry_new();
    button2 = gtk_button_new_with_mnemonic("ADD NEW STUDENT");
    g_signal_connect(button2, "clicked", G_CALLBACK(button_student), entry);
    g_signal_connect(entry, "activate", G_CALLBACK(button_student), entry); // press enter to call funtion
    
    vbox = gtk_vbox_new(0,0);
    gtk_box_pack_start(GTK_BOX(vbox), entry, 0,0,0);
    gtk_box_pack_start(GTK_BOX(vbox), button2, 0,0,0);
    
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    gtk_widget_show_all(window);
}

int main (int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *vbox;
    
    GtkWidget *toolbar;
    GtkToolItem *openTb;
    GtkToolItem *addStudentTb;
    GtkToolItem *sep;
    GtkToolItem *infoTb;
    GtkToolItem *exitTb;
    
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
    
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
    
    openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);
    
    addStudentTb = gtk_tool_button_new_from_stock(GTK_STOCK_ADD);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), addStudentTb, -1);
    
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);
    
    infoTb = gtk_tool_button_new_from_stock(GTK_STOCK_INFO);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), infoTb, -1);
    
    exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);
    
    g_signal_connect(G_OBJECT(openTb), "clicked", G_CALLBACK(open_dialog), GTK_WINDOW(window));
    g_signal_connect(G_OBJECT(addStudentTb), "clicked", G_CALLBACK(add_student), GTK_WINDOW(window));
    g_signal_connect (G_OBJECT(infoTb), "clicked", G_CALLBACK(show_dialog), GTK_WINDOW(window));
    g_signal_connect(G_OBJECT(exitTb), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all (window);
    
    gtk_main();
    
    return 0;
}
