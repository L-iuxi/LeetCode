#include<stdio.h>
#include<string.h>
int main()
{
    int arr[1000];
    int target;
    int i=0;
    for(int i=0;i<1000;i++)
    {
        scanf("%d,",&arr[i]);
        
        if(arr[i]==']')
        {
            arr[i]='\0';
            printf("no");
            break;
        }
    }
    //arr[i]='\0';
    int len=strlen(arr);
    printf("%d",len);
    for(int j=0;j<len;j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}