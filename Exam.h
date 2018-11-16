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
enum bool compare(char, char);

// check the letter of the grade by using if else to fine the right letter
enum grade check(double);

//returns array of correct answers
Exam * getAnswers(char * filename);

//get the Name of the class from the file located at the top of the file
char * getClassName(char * filename);

//get the names of the students to be displayed
Student * getStudentInfo();

//get each students answers
Student * getStudentAnswers(char * filename);

//returns the number of students in the class
int getNumOfS(char * filename);

//returns the number of questions on the exam
int getNumOfQ(char * filename);

//based on answers of he students and the answers of the exam 
double  computerScore(char[], char[]);

#endif /* Exam_h */
