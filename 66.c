/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void hanshu(int *nums,int i)
 {
    nums[i] = nums[i] - 10;
    nums[i-1] = nums[i-1] + 1;
 }
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (result == NULL) { 
        return NULL;
    }
    *returnSize =  digitsSize;
    for(int i = 0;i < digitsSize;i++)
    {
        result[i] = digits[i];
        if(i == digitsSize - 1)
        {
            result[i] = digits[i] + 1;
        }
    }

    for(int i = digitsSize-1;i > 0;i--)
    {
        if(result[i] >= 10)
        {
            hanshu(result,i);
           // (*returnSize)++;
        }else{
            break;
        }
    }

    if (result[0] >= 10) {
        int* ans = (int*)malloc(sizeof(int) * (digitsSize + 2));
         if (ans == NULL) {  
            free(result);  
            return NULL;
        }
        ans[0] = 1;
        ans[1] = result[0] - 10;
        //if(digitsSize >= 3)
        //{
        for(int i = 1;i < digitsSize;i++)
        {
            ans[i+1] = result[i];
        }
        *returnSize = digitsSize+1;
        //} 
        free(result);
        return ans;
    }
    return result;
}