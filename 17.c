/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
   int *result = (int*)malloc(sizeof(int) *100);
   *returnSize = 0;
   for(int i = 0;i < numsSize;i++)
   {
    for(int j = i+1;j < numsSize;j++)
   {
    if(nums[i] == nums[j])
    {
        result[*returnSize] = nums[i];
        (*returnSize)++;
        break;
    }
   }
   } 
   return result;
}