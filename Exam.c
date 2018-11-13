//
//  Exam.c
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#include "Exam.h"

grade check(double g){

  if(g >= 90.0 && g <= 100.0){
    return A; 
  else if(g >= 80.0 && <= 89.9){
    return B; 
  else if(g >= 70.0 && <= 79.9){
    return  C; 
  else if(g >= 60.0 && g <= 69.90{
    return D; 
  else {
     return F; 
  } 
}

bool compare(char s, char a){
   if(s == a)
      return TRUE;
   else
     return FALSE;
}

double average(double s, double a){
   double ave;
   ave = s/d * 100;
   return ave; 
}
