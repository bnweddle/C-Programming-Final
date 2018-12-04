//
//  Student.h
//  
//
//  Created by Ahmed Alkhraissi on 11/9/18.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>

Student * getStudentInfo();
Student * getStudentAnswers(char *);
Student * assignNames(Student *, Student *);
Student * assignGrade(Exam *, Student *, Student *);
void AppendStudentFile(char *);
#endif /* Student_h */
