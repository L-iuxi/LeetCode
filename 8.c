int removeElement(int* nums, int numsSize, int val) {
   int n = numsSize-1;
   int i = 0;
   int t;
   if(numsSize == 1)
   {
    if(nums[0] == val)
    {
        return 0;
    }else{
        return 1;
    }
   }
   if(numsSize == 0)
   {
    return 0;
   }
    while(i <= n)
    {
        if(nums[i] == val)
        {
            if(nums[n] != val)
            {
            t = nums[i];
            nums[i] = nums[n];
            nums[n] = t;
            }else{
                n--;
                continue;
            }
        }
        i++;
    }
    return i;
}