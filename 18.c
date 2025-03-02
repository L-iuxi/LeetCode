/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void findmax(int* arr, int n,int* result)
 {
        int *stack = (int*)malloc(sizeof(int) * n);
        int top = -1;
        for(int i = 0;i < n;i++)
        {
            while(top >= 0 && arr[stack[top]] < arr[i])
            {
                result[stack[top]] = arr[i];
                top--;
            }
            stack[++top] = i;
           
        }
         while(top >= 0)
            {
                result[stack[top]] = -1;
                top--;
            }
        free(stack);
 }
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * nums2Size);
    int *ans  = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    findmax(nums2,nums2Size,result);

    for(int i = 0;i < nums1Size;i++)
    {
        for(int j = 0;j < nums2Size;j++)
        {
            if(nums1[i] == nums2[j])
            {
                ans[i] = result[j];
                break;
            }
        }
    }
    free(result);
    return ans;
}