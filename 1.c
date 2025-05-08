int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
 void digui(int target,int *candidates ,int candidatesSize,int *current,int currentsize,int **result,int start,int *returnColumnSizes,int *returnSize)
 {
    if(target == 0)
    {
         result[*returnSize] = (int*)malloc(sizeof(int*)*currentsize);
         for(int i = 0;i < currentsize;i++)
         {
            result[*returnSize][i] = current[i];
         }
         returnColumnSizes[*returnSize] = currentsize;
         (*returnSize)++;
         return;
    }
    for(int i = start;i < candidatesSize;i++)
    {
        if(candidates[i] > target)
        {
            break;
        }
        if(i > start && candidates[i-1] == candidates[i])
        {
            continue;
        }
        current[currentsize] = candidates[i];
        digui(target - candidates[i],candidates,candidatesSize,current,currentsize+1,result,i,returnColumnSizes,returnSize);
    }

 }
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **result = (int**)malloc(sizeof(int*)*150);
    *returnColumnSizes = (int*)malloc(sizeof(int)*150);
    *returnSize = 0;
     qsort(candidates, candidatesSize, sizeof(int),compare);
     int *current = (int*)malloc(sizeof(int)*150);
    digui(target,candidates,candidatesSize,current,0,result,0,*returnColumnSizes,returnSize);
    free(current); 
    return result;
}
