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

// to compare to 'char' student answer and the 'char' correct answer return boolean: done already
enum bool compare(char, char);

// check the letter of the grade by using if else to fine the right letter: done already
enum grade check(double);

//get the names of the students to be displayed: done already
Student * getStudentInfo();

//should read the lines of how many students there are: numOfS, and malloc space for that many students
//then it should read through the lines and store the values of the student id and the students answers 
//then it should return that array of students
Student * getStudentAnswers(char * filename, int numOfS);

//should just read two lines, one line with the numOfS and numOfQ and then the check line with the exam answers
//should read the given file and store the values of numOfS, numOfQ, answers in the Exam and return it
Exam * getExamInfo(char * filename):

//based on answers of he students and the answers of the exam 
double  computerScore(char[], char[]);

#endif /* Exam_h */
