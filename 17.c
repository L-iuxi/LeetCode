/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int left = 0,right = *matrixColSize -1,top = 0,bottom = matrixSize - 1;
    *returnSize = 0;
    int *result = (int*)malloc(sizeof(int) * (*matrixColSize) * matrixSize);

    if((*matrixColSize) == 0 || matrixSize == 0)
    {
        return result;
    }
    if((*matrixColSize) == 1)
    {
        for(int i = 0;i < matrixSize;i++)
        {
            result[(*returnSize)++] = matrix[i][0];
        }
        return result;
    }

    if((matrixSize) == 1)
    {
        for(int i = 0;i < (*matrixColSize);i++)
        {
            result[(*returnSize)++] = matrix[0][i];
        }
        return result;
    }
    while(top <= bottom && left <= right)
    {
        for(int i = left;i <= right;i++)
        {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;
        for(int i = top;i <= bottom;i++)
        {
            result[(*returnSize)++] = matrix[i][right];
        }
     right--;

        if(top <= bottom)
        {
            for(int i = right;i >= left;i--)
            {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom;i >= top;i--)
            {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }

    }
    return result;
}