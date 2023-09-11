#include<stdio.h>
#include<stdint.h>
#include<string.h>
float funperce(int marks[],int n);
struct strudentmarks//structure defination with variable 
{
    int ID;
    char name[50];
    int submarks[6];
    int d,m,y;
    char gen;
    float per;

}MARK;

int main()
{
    printf("THIS IS STUDENT MARKS:\n");
    printf("ENTER THIS FORMATE ID/NAME/SIX SUBJECTS MARKS/DOB/GENDER(M/F)\n");
    printf("ENTER ID:");
    scanf("%d",&MARK.ID);
    printf("ENTER NAME:");
    scanf("%s",MARK.name);
    printf("ENTER SIX SUB MARKS:\n");
    for(int i=0;i<6;i++){
      printf("SUBJ:");
      scanf("%d",&MARK.submarks[i]);}
    printf("ENTER DD/MM/YYYY:");
    scanf("%d/%d/%d",&MARK.d,&MARK.m,&MARK.y);
    printf("ENTER GEN(M/F:)");
    scanf(" %c",&MARK.gen);
    MARK.per=(float)funperce(MARK.submarks,6);
    printf("ID:%d\n NAME:%s\n DOB:%d/%d/%d\n PERCENTAGE:%.2f\n GEN:%c",MARK.ID,MARK.name,MARK.d,MARK.m,MARK.y,MARK.per,MARK.gen);
}
float funperce(int marks[],int n)
{
   int i;
   long int t=0;
   for(i=0;i<n;i++)
   {
      t=t+marks[i];
   }
   float per=(float)(t/6.0);
   return per;
}
