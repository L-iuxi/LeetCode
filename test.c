#include<stdio.h>
int main()
{
    int n=1;
    int day;
    scanf("%d",&day);
    for(int i = 0;i < day-1;i++)
    {
        n = 2 * (n + 1);
    }
    printf("\n%d",n);
    return 0;
}