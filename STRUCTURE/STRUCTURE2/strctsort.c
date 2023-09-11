#include<stdio.h>
#include<string.h>
#define N 5
typedef struct strctsort
{
    char name[100];
}sort1;

void mysort(struct strctsort str[],int n);
int main()
{
    sort1 sort[N];
    int i;
    printf("enter data to sort ...\n");
    for(i=0;i<N;i++)
    {
        printf("name:");
        scanf("%s",sort[i].name);
    }
    mysort(sort,N);
    for(i=0;i<N;i++)
    {
        puts(sort[i].name);
    }
}

int compare(char *str,char *str1){
    char *ptr=str;
    char *ptr1=str1; 
   while(*ptr&&*ptr1)
    {
        if(*ptr<*ptr1)
        {
            return -1;
        }
        else if(*ptr>*ptr1)
        {
            return 1;
        }
        *ptr++;
        *ptr1++;
    }
    if(*ptr==0&&*ptr1==0)
    return 0;
    else if(*ptr==0)
    return -1;
    else 
    return 1;
}
void mysort(struct strctsort str[],int n) 
{  
    int i, j;
    char temp[20];
 for(i=0;i<n;i++)
 {
    for (j=i+1;j<n;j++)
    {
      if(compare(str[i].name,str[j].name)>0)
     {
           strcpy(temp,str[i].name) ;
           strcpy(str[i].name ,str[j].name);
           strcpy(str[j].name,temp);
     }
    }
  } 
}