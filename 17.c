/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int* a,int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

 void back(int *arr,int n,int start,int **result,int *returnColumnSizes,int *returnSize)
 {
    if(start == n)
    {
        result[*returnSize] = (int*)malloc(sizeof(int) * n);
        for(int i = 0;i < n;i++)
        {
            result[*returnSize][i] = arr[i];
           
        }
         returnColumnSizes[*returnSize] = n;
         (*returnSize)++;
        return;
    }
    for(int i = start;i < n;i++)
    {
        swap(&arr[start],&arr[i]);

        back(arr,n,start+1,result,returnColumnSizes,returnSize);

        swap(&arr[start],&arr[i]);
    }
 }
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int fact = factorial(numsSize);
    int **result = (int**)malloc(sizeof(int*) * fact);
    *returnColumnSizes = (int*)malloc(sizeof(int) * fact); 

     *returnSize = 0;
    back(nums,numsSize,0,result,*returnColumnSizes,returnSize);

    return result;
}