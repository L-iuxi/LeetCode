int maxab(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
int subarraySum(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0;i < numsSize;i++)
    {
        int start = maxab(0,i-nums[i]);
        for(int j = start;j <= i;j++)
        {
            sum += nums[j];
        }
    }
    return sum;
}