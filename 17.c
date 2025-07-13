/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * 100);
    (*returnSize) = 0;
    for(int i = 1;i < heightSize;i++)
    {
        int t = i-1;
        if(height[i-1] > threshold)
        {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return result;
}