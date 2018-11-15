//
//  Exam.c
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#include "Exam.h"

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

char * getClassName(char * filename){
   FILE * fp = fopen(filename, "r");
   char * name = "";
   
   fscanf(fp, "%s", name);
   fclose(fp);
   return name; 
} 


