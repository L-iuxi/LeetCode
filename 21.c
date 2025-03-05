/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int *stack = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int top = -1;
    int *result = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0;i < numsSize;i++)
    {
        result[i] = -1;
    }
    for(int i = 0;i < 2 * numsSize;i++)
    {
        int index = i % numsSize;
        while(top > -1&& nums[stack[top]] < nums[index])
        {
            int prevIndex = stack[top--]; 
            result[prevIndex] = nums[index];
        }
        if(i < numsSize)
        {
            top++;
            stack[top] = i;
        }
    }
    free(stack);
    return result;
}