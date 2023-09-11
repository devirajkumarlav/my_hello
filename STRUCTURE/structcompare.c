
#include<stdio.h>
#include<stdint.h>
#include<string.h>

struct structcompare
{
   int x;
   char str[10];
   float f;
}cmp1,cmp2;
int camp(struct structcompare cmp1,struct structcompare cmp2);
int main()
{
    printf("enter structure 1 value int/string/float:");
      scanf("%d",&cmp1.x);
      scanf("%s",cmp1.str);
      scanf("%f",&cmp1.f);
      printf("enter structure 2 value int/string/float:");
      scanf("%d",&cmp2.x);
      scanf("%s",cmp2.str);
      scanf("%f",&cmp2.f);
      int i=camp(cmp1,cmp2); //sending the veriable
      if(i)
      printf("both are same ...");
      else
      printf("both are not same ...");
}
int camp(struct structcompare cmp1,struct structcompare cmp2)
{
   if((cmp1.x==cmp2.x)&&((float)cmp1.f==(float)cmp2.f))
   {
    if(strcmp(cmp1.str,cmp2.str)==0)
    {
      return 1;
    }
    else{
      return 0;
    }
   }
   else
   {
    return 0;
   }
}

