//
//  functionsFile.c
//

#include "functionsFile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



Student * getStudentInfo()
{
    //This works!! Don't change.
    FILE * fp;
    fp = fopen("students.txt", "r");
    int  num = 0;
    
    fscanf(fp, "%d\n", &num);
    Student * s = malloc(num*sizeof(Student));
    s->num = num;
    
    char line[40];
    for(int i = 0; i < num; i++)
    {
        if(fgets(line, 40, fp)!=NULL)
        {
            char * token = strtok(line, ",");
            s[i].id = atoi(token);
            
            token = strtok(NULL, ",");
            s[i].name = strdup(token);
        }
    }
    fclose(fp);
    return s;
}

Student * getStudentAnswers(char * filename)
{
    //This works now!
    FILE * fp = fopen(filename, "r");
    int numOfS = 0;
    int numOfQ = 0;
    int classID = 0;
    
    fscanf(fp, "%d %d %d", &numOfS, &numOfQ, &classID);
    
    char * answers = malloc((numOfQ + 1) * sizeof(char));
    fscanf(fp, "%s\n", answers);
    
    Student * s = malloc(numOfS * sizeof(Student));
    s->num = numOfS;
    
    char line[40];
    for(int i = 0; i < numOfS; i++)
    {
        if(fgets(line, sizeof line, fp) != NULL)
        {
            char * token = strtok(line, ",");
            s[i].id = atoi(strdup(token));
            token = strtok(NULL, ",");
            s[i].answers = strdup(token);
        }
    }
    fclose(fp);
    return s;
}

Student * assignNames(Student * fs, Student * es)
{
    //This works!
    for(int j = 0; j < es->num; j++)
    {
        for(int i = 0; i < fs->num; i++)
        {
            if(fs[i].id == es[j].id)
            {
                es[j].name = fs[i].name;
            }
        }
    }
    return es;
}

Student * assignGrade(Exam * e, Student * n, Student * es)
{
    //Works: but outputs different than I want.
    for(int i = 0; i < es->num; i++)
    {
        double score = computeScore(e->answers, es[i].answers);
        enum grade g = check(score);
        char c = getGrade(g);
        n[i].grade = c;
    }
    return n;
}

void AppendStudentFile(char * name)
{
    Student * s = getStudentInfo();
    int newNum = s->num + 1;
    
    FILE * fp = fopen("students.txt", "w");
    fprintf(fp,"%d\n", newNum);
    for(int i  = 0; i < s->num; i++)
    {
        fprintf(fp,"%d,%s\n", s->id, s->name);
    }
    fprintf(fp,"%d,%s\n", newNum, name);
    fclose(fp);
}
