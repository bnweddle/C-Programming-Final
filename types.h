#ifndef types_h
#define types_h

enum bool { FALSE, TRUE };
enum grade { A, B, C, D, F};

typedef struct Class {
    int num;
    int id;
    char * name;
}Class;

typedef struct Student{
    int id;
    int num;
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
