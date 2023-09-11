#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define N 2//no of students
float funperce(int marks[],int n);
struct strudentmarks//structure defination with variable 
{
    int ID[N];
    char name[N][50];
    int submarks[N][6];
    int d[N],m[N],y[N];
    char gen[N];
    float per[N];
}MARK; //variable name of structure

int main()
{
    printf("THIS IS STUDENT MARKS:\n");
    printf("ENTER THIS FORMATE ID/NAME/SIX SUBJECTS MARKS/DOB/GENDER(M/F)\n");
    int i,j;
    for(i=0;i<N;i++){
    printf("ENTER ID:");
    scanf("%d",&MARK.ID[i]);
    printf("ENTER NAMES:");
        scanf("%s",MARK.name[i]);
        printf("ENTER SIX SUB MARKS:\n");
        for(j=0;j<6;j++){//take six subject 
        printf("SUBJ:");
        scanf("%d",&MARK.submarks[i][j]);}
    printf("ENTER DD/MM/YYYY:");
    scanf("%d/%d/%d",&MARK.d[i],&MARK.m[i],&MARK.y[i]);
    printf("ENTER GEN(M/F):");
    scanf(" %c",&MARK.gen[i]);
    MARK.per[i]=(float)funperce(MARK.submarks[i],6);
    }
     // MARK.per[i]=0.0f; //add 0 at last index
      int index;
      float in;
      for (int k = 0; k < N; k++)
      {
        if(k==0)
        {
         in=MARK.per[k];
         index=k;
         }
         else if((float)in<(float)MARK.per[k])
         {
            in=MARK.per[k];
            index=k;
          }
      }
      //printf("%d",index);
    printf("ID:%d\n NAME:%s\n DOB:%d/%d/%d\n PERCENTAGE:%.2f\n GEN:%c",MARK.ID[index],MARK.name[index],MARK.d[index],MARK.m[index],MARK.y[index],MARK.per[index],MARK.gen[index]);
    return 0;
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
