/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int findm(int *arr,int len,int start,int m)
 {
    for(int i = start;i < len;i++)
    {
        if(arr[i] > m)
        {
            return arr[i];
        }
    }
    return -1;
 }

 int findnum(int *arr,int m,int len)
 {
    for(int i = 0;i < len;i++)
    {
        if(arr[i] == m)
        {
            return i;
        }
    }
    return -1;
 }
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result= (int*)malloc(sizeof(int ) * nums1Size);
    *returnSize = nums1Size;
    int top = 0;
    for(int i = 0;i < nums1Size;i++)
    {
        int point = findnum(nums2,nums1[i],nums2Size);
        result[top] = findm(nums2,nums2Size,point,nums1[i]);
            top++;
    }
    return result;
}