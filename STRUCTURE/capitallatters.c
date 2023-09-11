#include<stdio.h>
#define N 2
struct capitallatters
{
    char str[100];
}CAPS[N];
struct capitalatters *cptl(struct capitallatters ptr[]);
int main()
{
    printf("this small latters to capital latters ...\n");
    for(int i=0;i<N;i++)
    {
        printf("enter string:");
        fgets(CAPS[i].str,100,stdin);
    }
    cptl(CAPS);
    puts(CAPS[0].str);
    puts(CAPS[1].str);
}
struct capitalatters *cptl(struct capitallatters ptr[])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;ptr[i].str[j]!=0;j++)
        {
            if(ptr[i].str[j]>='a'&&ptr[i].str[j]<='z')
            {
                ptr[i].str[j]=ptr[i].str[j]-32;
            }
        }
    }
}