#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct Student addStudent(const char *name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, NAME_LENGTH);
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Name: %s, Math: %d, Physics: %d, Informatics: %d, Total: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}