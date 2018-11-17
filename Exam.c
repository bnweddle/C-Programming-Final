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
    return A;
  } 
  else if(g >= 80.0 && g <= 89.9){
    return B; }
  else if(g >= 70.0 && g <= 79.9){
    return C; }
  else if(g >= 60.0 && g <= 69.9){
    return D; }
  else {
     return F; 
  }
}

const char getGrade(enum grade g)
{
  switch(g){
    case A: return 'A'; break;
    case B: return 'B'; break;
    case C: return 'C'; break;
    case D: return 'D'; break;
    case F: return 'F'; break;
 }
}
enum bool compare(char e, char s){
   if(e  == s)
      return TRUE;
   else
     return FALSE;
}

double computeScore(char * exam, char * student){
  //This works! 
  //first chars of strings
   char * e = exam;
   char * s = student;
   double eCount = 0.0;
   double count = 0.0;

   while(*e != '\0'){
     if(compare(*e,*s)==TRUE)
       count++;
     eCount++;
     e++;
     s++;
   }
   count = (count/eCount) * 100;
   printf("%f\n", count);
   return count;
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
        s[i].id = atoi(token);
 
        token = strtok(NULL, ","); 
        s[i].name = strdup(token);
       }
    }
   fclose(fp);
   return s;
}

Exam * getExamInfo(char * filename){

  //This works!
  FILE * fp = fopen(filename, "r");
  Exam * e = malloc(sizeof(Exam));

  int numOfS = 0;
  int numOfQ = 0;

  fscanf(fp, "%d %d", &numOfS, &numOfQ);
  e->numOfS = numOfS;
  e->numOfQ = numOfQ;

  char * answers = malloc((numOfQ+1) *sizeof(char));
  fscanf(fp, "%s", answers);
  e->answers = answers;

  fclose(fp);
  return e;
}


Student * getStudentAnswers(char * filename){
  //This works now! 
  FILE * fp = fopen(filename, "r");
  int numOfS = 0;
  int numOfQ = 0;

  fscanf(fp, "%d %d", &numOfS, &numOfQ);

  char * answers = malloc((numOfQ+1) *sizeof(char));
  fscanf(fp, "%s\n", answers);

  Student * s = malloc(numOfS * sizeof(Student));
  s->num = numOfS;

  char line[40];
  for(int i = 0; i < numOfS; i++){
     if(fgets(line, 40, fp) != NULL){
       char * token = strtok(line, ",");
       s[i].id = atoi(strdup(token));
       token = strtok(NULL, ",");
       s[i].answers = strdup(token);
     }
  }
  fclose(fp);
  return s;
}

Student * assignNames(Student * fs, Student * es){
  int count = 0;
 for(int j = 0; j < es->num; j++){
  for(int i = 0; i < fs->num; i++){
    //printf("%d\n", es->id);
      if(fs[i].id == es[j].id){
         es[j].name = fs[i].name;
      }
    }
  }
  return es;
}
