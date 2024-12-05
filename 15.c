int singleNumber(int* nums, int numsSize) {
    if(numsSize == 1)
    {
        return nums[0];
    }
    int fast = 0;
    int slow = 0;
    for(int i = 0;i < numsSize;i++)
{
    for(int j = 0;j < numsSize;j++)
    {
        if(i == j)
        {
            continue;
        }
        
        if(nums[i] == nums[j])
        {
            break;
        }
        if(j == numsSize - 1)
        {
            return nums[i];
        }
    }
}
    return nums[numsSize-1];
}