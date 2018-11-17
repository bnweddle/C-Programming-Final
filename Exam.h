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
enum bool compare(char e, char s);

// check the letter of the grade by using if else to fine the right letter: done already
enum grade check(double);

//returns the grade letter;
char getGrade(enum grade g);

//get the names of the students to be displayed: done already
Student * getStudentInfo();

//should read the lines of how many students there are: numOfS, and malloc space for that many students
//then it should read through the lines and store the values of the student id and the students answers 
//then it should return that array of students
Student * getStudentAnswers(char * filename);//done already

//should just read two lines, one line with the numOfS and numOfQ and then the check line with the exam answers
//should read the given file and store the values of numOfS, numOfQ, answers in the Exam and return it
Exam * getExamInfo(char * filename); //done already

//based on answers of he students and the answer of the exam 
double computeScore(char * exam, char * student);//done already

//Need to pass in the Student * from the file and then the specific Student * read from the exam file
//Then assign the if a matching id is found, assign the name of the fs to the name of es 
//then return the modified es
Student * assignNames(Student * fs, Student * es); //done already!

//Assign the grades that are computed and get the Letter grade and assign it 
//to the Student->grade for each student in the exam and then return the 
//modified Student *: n(should be the one with the names-from assignNames)
Student * assignGrades(Exam * e, Student * n, Student * es);//done already


#endif /* Exam_h */
