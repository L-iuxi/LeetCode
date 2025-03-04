#define Max(a,b) ((a > b) ? (a):(b))

int largestRectangleArea(int* heights, int heightsSize) {
    int top = -1;;
    int *stack = (int*)malloc(sizeof(int) * (heightsSize + 1));
    int max = 0;
    for(int i = 0;i <=heightsSize;i++)
    {
        //int current = heights[i];
         int currentHeight = (i == heightsSize) ? 0 : heights[i];
        while(top > -1&&currentHeight < heights[stack[top]])
        {
           // int len = (top == -1) ? i:(i - stack[top] - 1);
            int area = heights[stack[top--]];
            int len = (top == -1) ? i:(i - stack[top] - 1);
            max = Max(max,area*len);

        }
        //top++;
       stack[++top] = i;
    }
    free(stack);
    return max;
}