#include<stdio.h>
#define N 5

struct countBG
{
    char name[100];
    int age;
    char gen;
}cboys[N];
int countmale(struct countBG *cboys);
int countfemale(struct countBG *cboys);
int main()
{
  printf("enter name and age and gender ...\n");
  int i,j;
  for(i=0;i<N;i++)
  {
    printf("name:");
    scanf("%s",cboys[i].name);
    printf("age:");
    scanf("%d",&cboys[i].age);
    printf("gender:");
    scanf(" %c",&cboys[i].gen);
  }
    int x=countmale(cboys);
    int y=countfemale(cboys);
    printf("male :%d and female :%d",x,y);
} 
int countmale(struct countBG *cboys)
{
    int c=0;
    for(int i=0;i<N;i++)
    {
        if((cboys[i]).gen=='m'||(cboys[i]).gen=='M')
        {
            c++;
        }
          
    }
    return c;
}
int countfemale(struct countBG *cboys)
{
    int c=0,j;
    for(int i=0;i<N;i++)
    {
        if((cboys[i]).gen=='f'||(cboys[i]).gen=='F')
        {
           c++;
        }       
    }
    return c;
}

