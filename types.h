#ifndef types_h
#define types_h

typedef enum { FALSE, TRUE } bool;
typedef enum { F, A, B, C, D} grade;

typedef struct Class {
    int id;
    char * name;
}Class;

typedef struct Student{
    int id;
    char * name;
    int grade;
    char * answers;
}Student;

typedef struct Exam {
    char * answers;
    int numStd;
    int numQ;
}Exam;




#endif /* types_h */
