int func(int a,int b)
{
    if(a > b)
    {
        return a - b;
    }
        return b - a;
    
}
int findClosest(int x, int y, int z) {
    int a = func(x,z);
    int b = func(y,z);
    
    if(a < b)
    {
        return 1;
    }else if(b < a)
    {
        return 2;
    }
        return 0;
    
  
}