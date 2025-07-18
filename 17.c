int minimumChairs(char* s) {
    int max = 0;
    int sum = 0;
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(s[i] == 'E')
        {
            sum++;
        }
        if(s[i] == 'L')
        {
            sum--;
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}