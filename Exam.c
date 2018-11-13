//
//  Exam.c
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#include "Exam.h"

int check(double g){
 
  if(g >= 90.0 && g <= 100.0){
    return 1; //A
  else if(g >= 80.0 && <= 89.9){
    return 2; //B
  else if(g >= 70.0 && <= 79.9){
    return  3; //C
  else if(g >= 60.0 && g <= 69.90{
    return 4; //D
  else {
     return 5; //F
  }
  
}

bool compare(char s, char a){
   bool t = FALSE;
   if(s == a)
      t = TRUE;
   return t;
}

double average(double s, double a){
   double ave;
   ave = s/d * 100;
   return ave; 
}
