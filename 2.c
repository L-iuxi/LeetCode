void moveZeroes(int* nums, int numsSize) {
    int fast=0;
    int low=0;
    int t;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[fast]!=0)
        {
            t=nums[fast];
            nums[fast]=nums[low];
            nums[low]=t;
            low++;
        }

        fast++;
        //low++;
    }
    //return nums;
}