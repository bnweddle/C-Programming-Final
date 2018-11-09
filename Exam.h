//
//  Exam.h
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#ifndef Exam_h
#define Exam_h

#include "types.h"
#include <stdio.h>

// to compare to 'char' student answer and the 'char' correct answer return boolean
bool compare(char, char);

// to calculate the grade avrage by the 'int' student grade divided by 'int' total grade return double
double avrage(int, int);

// check the letter of the grade by using if else to fine the right letter
int check(double);

void readFile();



#endif /* Exam_h */
