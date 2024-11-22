int maxArea(int* height, int heightSize) 
{
    int left = 0;
    int right = heightSize-1;
    int max = 0;
    int square;
   while(left < right)
   {
    if(height[left] < height[right])
    {
        square = height[left] * (right - left);
        left++;
    }
    else
    {
        square = height[right] * (right - left);
        right--;
    }
    if(square > max)
    {
        max = square;
    }
    
   }
    
    return max;
}