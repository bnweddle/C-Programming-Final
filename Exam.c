//
//  Exam.c
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#include "Exam.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum grade check(double g){
 
  if(g >= 90.0 && g <= 100.0){
    return A;} 
  else if(g >= 80.0 && g <= 89.9){
    return B; }
  else if(g >= 70.0 && g <= 79.9){
    return  C; }
  else if(g >= 60.0 && g <= 69.90){
    return D; }
  else {
     return F; 
  } 
}

enum bool compare(char s, char a){
   if(s == a)
      return TRUE;
   else
     return FALSE;
}

Exam * getAnswers(char * filename){
   //it is the third line.
   int lineNumber = 3;
    
}

Student * getStudentInfo(){
  //This works!! Don't change.
  FILE * fp;
  fp = fopen("students.txt", "r");
  int  num = 0;
  
  fscanf(fp, "%d\n", &num);
  Student * s = malloc(num*sizeof(Student));
  s->num = num;
   
  char line[40];
    for(int i = 0; i < num; i++){
       if(fgets(line, 40, fp)!=NULL){
        char * token = strtok(line, ",");
        s[i].id = atoi(strdup(token));
 
        token = strtok(NULL, ","); 
        s[i].name = strdup(token);
       }
    }
   fclose(fp);
   return s;
} 




