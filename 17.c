int binary(char *s, int l, int x) {
    int r = l;
    for (; x; x >>= 1) {
        s[r++] = '0' + (x & 1);
    }
    for (int i = l, j = r - 1; i < j; i++, j--) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    return r;
}
int toint(char *s,int l,int len)
{
    int sum = 0;
    for(;l<len;l++)
    {
        sum = sum*10 + s[l] - '0';
    }
    return sum;
}
char* convertDateToBinary(char* date) {
    int year = toint(date,0,4);
    int month = toint(date,5,7);
    int day = toint(date,8,10);

char *res = (char *)calloc(128, 1);
    int i = binary(res, 0, year);
    res[i++] = '-';
    i = binary(res, i, month);
    res[i++] = '-';
    i = binary(res, i, day);
    return res;

}