#include<stdio.h>
#define N 3
struct date
{
    int d,m,y;
}DATE[N];
int olddate(struct date arr[ ]);
int main()
{
    printf("enter date formate dd/mm/yyyy ...\n");
     int i;
     for(i=0;i<N;i++)
     {
        printf("date:");
        scanf("%d/%d/%d",&DATE[i].d,&DATE[i].m,&DATE[i].y);
     }
     int x=olddate(DATE);
     printf("old date from given:");
     printf("%d/%d/%d",DATE[x].d,DATE[x].m,DATE[x].y);
}
int olddate(struct date arr[ ])
{
    int i,j,s,yr,mt,dt;
    for(i=0;i<N;i++)
    {
        if(i==0)
        { 
          s=i;
          yr=arr[i].y;mt=arr[i].m;dt=arr[i].d;  
        }
        else if(yr<arr[i].y)
        {
           yr=yr;mt=mt;dt=dt;  
        }
           else if (yr>arr[i].y)
           {
              s=i;
              yr=arr[i].y;mt=arr[i].m;dt=arr[i].d;  
           }
           else if(mt<arr[j].m)
           {
            yr=yr;mt=mt;dt=dt;  
           }
           else if(mt>arr[j].m)
           {
            s=i;
            yr=arr[i].y;mt=arr[i].m;dt=arr[i].d;  
           }
           else if(dt<arr[j].d)
           {
            yr=yr;mt=mt;dt=dt;  
           }
           else if(dt>arr[j].d)
           {
            s=i;
            yr=arr[i].y;mt=arr[i].m;dt=arr[i].d;  
           }     
    }
    return s;
}