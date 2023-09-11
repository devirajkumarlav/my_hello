
#include<stdio.h>
#define N 3
struct date
{
    int dt,mt,yr;
};

struct student
{
int ID;
char name[50];
int marks[6];
struct date dob, doj;
float per;
char gender;
}oldone[N];

int olddate(struct student oldone[],int n);
int main()
{
    int i,j;
    printf("enter data ...\n");
    for(i=0;i<N;i++)
    {
        printf("ID:");
        scanf("%d",&oldone[i].ID);
        printf("NAME:");
        scanf("%s",oldone[i].name);
        for(int k=0;k<6;k++)
        {
            printf("MARKS:");
            scanf("%d",&oldone[i].marks[k]);
        }
        printf("DOB DD/MM/YYYY:");
        scanf("%d/%d/%d",&oldone[i].dob.dt,&oldone[i].dob.dt,&oldone[i].dob.dt);
         printf("DOJ DD/MM/YYYY:");
        scanf("%d/%d/%d",&oldone[i].doj.dt,&oldone[i].doj.dt,&oldone[i].doj.dt);
        printf("gender(m/f):");
        scanf(" %c",&oldone[i].gender);
    }
    int x=olddate(oldone,N);
        printf("The oldest student is name: %s (ID: %d) year:%d/%d/%d\n", oldone[x].name, oldone[x].ID,oldone[x].dob.dt,oldone[x].dob.mt,oldone[x].dob.yr);
}

int olddate(struct student oldone[], int n)
{
    int index=0,i;
    for(i=1;i<N;i++)
    {
       if(oldone[i].dob.yr < oldone[index].dob.yr)
       {
        index=i;
       }
       else if(oldone[i].dob.yr == oldone[index].dob.yr &&
               oldone[i].dob.mt < oldone[index].dob.mt)
       {
        index=i;
       }
       else if(oldone[i].dob.yr == oldone[index].dob.yr &&
               oldone[i].dob.mt == oldone[index].dob.mt &&
               oldone[i].dob.dt < oldone[index].dob.dt)
               {
                index=i;
               }
    }
    return index;
}