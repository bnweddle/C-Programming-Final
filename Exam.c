//
//  Exam.c
//

#include "Exam.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum grade check(double g)
{
    if(g >= 90.0 && g <= 100.0)
        return A;
    else if(g >= 80.0 && g <= 89.9)
        return B;
    else if(g >= 70.0 && g <= 79.9)
        return C;
    else if(g >= 60.0 && g <= 69.9)
        return D;
    else
        return F;
}

char getGrade(enum grade g)
{
    switch(g)
    {
        case A: return 'A'; break;
        case B: return 'B'; break;
        case C: return 'C'; break;
        case D: return 'D'; break;
        case F: return 'F'; break;
    }
}

enum bool compare(char e, char s)
{
    if(e == s) return TRUE;
    else return FALSE;
}

double computeScore(char * exam, char * student)
{
    //This works!
    //first chars of strings
    char * e = exam;
    char * s = student;
    
    double eCount = 0.0;
    double count = 0.0;

    while(*e != '\0')
    {
        if(compare(*e,*s)==TRUE)
            count++;
        
        eCount++;
        e++;
        s++;
    }
    count = (count/eCount) * 100;
    return count;
}

Exam * getExamInfo(char * filename)
{
    //This works!
    FILE * fp = fopen(filename, "r");
    Exam * e = malloc(sizeof(Exam));
    
    int numOfS = 0;
    int numOfQ = 0;
    int classID = 0;
    
    fscanf(fp, "%d %d %d", &numOfS, &numOfQ, &classID);
    e->numOfS = numOfS;
    e->numOfQ = numOfQ;
    e->cID = classID;
    
    char * answers = malloc((numOfQ + 1) * sizeof(char));
    fscanf(fp, "%s", answers);
    e->answers = answers;
    
    fclose(fp);
    return e;
}


