
#include <stdio.h>
#define N 3

struct date {
    int dt, mt, yr;
};

struct student {
    int RLLNO;
    char name[100];
    struct date DOB, DOJ;
}find[N];

void printStudents(struct student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].RLLNO);
        printf("Name: %s\n", students[i].name);
        printf("DOB: %d/%d/%d\n", students[i].DOB.dt, students[i].DOB.mt, students[i].DOB.yr);
        printf("DOJ: %d/%d/%d\n", students[i].DOJ.dt, students[i].DOJ.mt, students[i].DOJ.yr);
    }
}

int main() {
    printStudents(find, N);

    return 0;
}
