
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool firstrow = false;
    bool firstcol = false;

    for(int i = 0;i < matrixSize;i++)
    {
        if(matrix[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }

    for(int i = 0;i < matrixColSize[0];i++)
    {
        if(matrix[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }

    for(int i = 1;i < matrixSize;i++)
    {
        for(int j = 1;j < matrixColSize[i];j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    
    for(int i = 1;i < matrixSize;i++)
    {
        for(int j = 1;j < matrixColSize[i];j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
               matrix[i][j] = 0;
            }
        }
    }

    if(firstcol)
    {
        for(int i = 0; i < matrixSize;i++)
        {
            matrix[i][0] = 0;
        }
    }

    if(firstrow)
    {
        for(int i = 0; i < matrixColSize[0];i++)
        {
            matrix[0][i] = 0;
        }
    }
}