#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 64

struct Student {
    char name[NAME_LENGTH];
    int math;
    int physics;
    int informatics;
    int total;
};

struct Student addStudent(const char *name, int math, int phy, int inf);
void printStudentInfo(struct Student student);

#endif