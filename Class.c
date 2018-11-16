//
//  Class.c
//  Created by Ahmed Alkhraissi on 11/9/18.

#include "Class.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

Class * showAllClasses(){

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
	c[i].id = atoi(token);
        
        token = strtok(NULL, ","); // token = CIS308
	c[i].name = token;
       }
    }
    fclose(fp);
    printf("%s", c[0].name);
    printf("%d", c[0].id);
     printf("%s", c[1].name);
    printf("%d", c[1].id);

    return c;
}

int main(int argc, char *argv[]) {

 // Class * classes = showAllClasses();
 // gcc `pkg-config --cflags gtk+-3.0` -o Class Class.c `pkg-config --libs gtk+-3.0`


  return 0;
}
