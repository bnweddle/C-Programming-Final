//
//  Class.c
//  Created by Ahmed Alkhraissi on 11/9/18.

#include "Class.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

Class * getClassesInfo(){
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

char * assignName(Class * c, int id)
{
    for(int i = 0;i < c->num; i++)
    {
        char * name = "";
        if(c->id == id)
            return c->name;
        else
           c++;
    }
    return NULL;
    
}

