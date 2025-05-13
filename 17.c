bool isPalindrome(int x) {
   if(x < 0 || (x % 10 == 0 && x != 0))
   {
    return false;
   }
    int num = 0;
    int start = x;
    while(start > num)
    {
        int index = start % 10;
        num =num *10 + index;
        start /= 10;
    }
    if(num  ==start || num / 10 == start)
    {
        return true;
    }else{
        return false;
    }
}