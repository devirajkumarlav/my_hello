#include <stdio.h>
#define N 3

struct date {
    int dt, mt, yr;
};

typedef struct  student {
    int ID;
    char name[50];
    int marks[6];
    struct date dob, doj;
    float per;
    char gender;
} oldone1;

int olddate( oldone1 oldone[], int n);
int main() {
    oldone1 oldone[N];
    printf("Enter data:\n");
    for (int i = 0; i < N; i++) {
        printf("ID: ");
        scanf("%d",&oldone[i].ID);
        printf("Name: ");
        scanf("%s", oldone[i].name);
        for (int k = 0; k < 6; k++) {
            printf("Marks: ");
            scanf("%d", &oldone[i].marks[k]);
        }
        printf("DOB (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &oldone[i].dob.dt, &oldone[i].dob.mt, &oldone[i].dob.yr);
        printf("DOJ (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &oldone[i].doj.dt, &oldone[i].doj.mt, &oldone[i].doj.yr);
        printf("Gender (m/f): ");
        scanf(" %c", &oldone[i].gender);
    }
    int oldestIndex = olddate(oldone, N);
    printf("The oldest student is: %s (ID: %d)\n", oldone[oldestIndex].name, oldone[oldestIndex].ID);

    return 0;
}


int olddate(struct student *oldone, int n) {
    int oldestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (oldone[i].dob.yr < oldone[oldestIndex].dob.yr)
            oldestIndex = i;
        else if (oldone[i].dob.yr == oldone[oldestIndex].dob.yr &&
                 oldone[i].dob.mt < oldone[oldestIndex].dob.mt)
            oldestIndex = i;
        else if (oldone[i].dob.yr == oldone[oldestIndex].dob.yr &&
                 oldone[i].dob.mt == oldone[oldestIndex].dob.mt &&
                 oldone[i].dob.dt < oldone[oldestIndex].dob.dt)
            oldestIndex = i;
    }
    return oldestIndex;
}
