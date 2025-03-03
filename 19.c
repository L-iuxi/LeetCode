int largestRectangleArea(int* heights, int heightsSize) {
    int top = -1;
    //int square;
    int *square = (int*)malloc(sizeof(int)*heightsSize);
     
     for (int i = 0; i < heightsSize; i++) {
        square[i] = heights[i];
    }
    for(int i = 0;i < heightsSize;i++)
    {
       int left = i - 1;  
        int right = i + 1; 
       
        
        while(left >= 0&&heights[left] >= heights[i])
    {
            square[i] += heights[i];
            left--;
    }
        while(right <= heightsSize-1&&heights[right] >= heights[i])
    {
            square[i] += heights[i];
            right++;
    }
        
    }
    
    for(int i = 0;i < heightsSize;i++)
    {
        if(square[i] > top)
        {
            top = square[i];
        }
    }
    free(square);
    return top;
}