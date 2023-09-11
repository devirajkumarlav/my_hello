#include<stdio.h>
#define N 3

struct date {
   int dt, mt, yr;
};

struct student {
    int RLLNO;
    char name[100];
    struct date DOB, DOJ;
} find[N];

int checkdate(struct date studate);

int main() {
    int i;
    printf("ENTER STUDENT DATA ....\n");
    for (i = 0; i < N; i++) {
        int x = 1;
        printf("Enter roll number: ");
        scanf("%d", &find[i].RLLNO);
        printf("Enter student name: ");
        scanf("%s", find[i].name);
        printf("Enter DOB (dd/mm/yyyy): ");
        while (x) {
            scanf("%d/%d/%d", &find[i].DOB.dt, &find[i].DOB.mt, &find[i].DOB.yr);
            if (checkdate(find[i].DOB)) {
               break;
            } else {
                printf("Please enter again...\n");
                printf("DOB: ");
            }
        }
        printf("Enter DOJ (dd/mm/yyyy): ");
        while (x) {
            scanf("%d/%d/%d", &find[i].DOJ.dt, &find[i].DOJ.mt, &find[i].DOJ.yr);
            if (checkdate(find[i].DOJ)) {
               break;
            } else {
                printf("Please enter again...\n");
                printf("DOJ: ");
            }
        }
    }
    
    return 0;
}

int checkdate(struct date studate) {
    int m = studate.mt;
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (studate.dt >= 1 && studate.dt <= 31) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (studate.dt >= 1 && studate.dt <= 30) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 2:
            if (studate.dt == 29) {
                if (((studate.yr % 4 == 0) && (studate.yr % 100 != 0)) || (studate.yr % 400 == 0)) {
                    return 1;
                }
            } else if (studate.dt >= 1 && studate.dt <= 28) {
                return 1;
            } else {
                return 0;
            }
            break;
        default:
            break;
    }
    return 0;
}
