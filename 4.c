#include<stdio.h>
#include<math.h>
int is_prime(int num) {//判断是否为素数
    if (num <= 1) 
        return 0;
    if (num == 2) 
        return 1;  
    if (num % 2 == 0) 
        return 0;  
    for (int i = 3; i <= sqrt(num); i += 2) 
    {  
        if (num % i == 0) 
            return 0;  
    }
    return 1;
}
int yesno(int n)
{
    int t = 1;
    int sum = 0;
    if(is_prime(n))
    {
        while(n / 10 != 0)
        {
            t++;
        }
        for(int i = 0;i < t;i++)
        {
            
            sum += n % 10;
            n = n / 10;
        }
        if(is_prime(sum))
        {
            return 1;
        }
        else{
            return 0;
        }
    }else{
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    if(yesno(n))
    {
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}