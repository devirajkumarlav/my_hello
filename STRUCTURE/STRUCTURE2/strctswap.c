#include<stdio.h>
#define N 2
struct strctswap
{
    char name[100];
    int age;
    float ft;
}swap[N];

void swapstrct(struct strctswap *ptr1,struct strctswap *ptr2 );
int main()
{
    int i;
    printf("enter data to swap ...\n");
    for(i=0;i<N;i++)
    {
       printf("enter name:");
       scanf("%s",swap[i].name);
       printf("enter age:");
       scanf("%d",&swap[i].age);
       printf("any float value:");
       scanf("%f",&swap[i].ft);
    }
    swapstrct(&swap[0],&swap[1]);
    printf("after swaping ...\n");
    printf("stucture 1-->");
    printf("name:%s age:%d float:%.2f\n",swap[0].name,swap[0].age,swap[0].ft);
    printf("stucture 2-->");
    printf("name:%s age:%d float:%.2f\n",swap[1].name,swap[1].age,swap[1].ft);
}
void swapstrct(struct strctswap *ptr1,struct strctswap *ptr2 )
{
    struct strctswap temp;
     temp=*ptr1;
     *ptr1=*ptr2;
     *ptr2=temp;
}
    
    
