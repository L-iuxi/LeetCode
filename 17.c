/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double culculate(int a,int b,int c,int d)
{
    double len =1.0 * abs((a-c)*(a-c)+(b-d)*(b-d));
    len = sqrt(len);
    return len;
}
bool confine(double len,int r)
{
    if(len <= 1.0*r)
    {
        return true;
    }
    return false;
}
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) *1008);
    memset(result, 0, sizeof(int) * 1008);
    (*returnSize) = 0;
    for(int j = 0;j < queriesSize;j++)
    {
        int a = queries[j][0];
        int b = queries[j][1];
        int r = queries[j][2];
    for(int i = 0;i < pointsSize;i++)
    {
        int c = points[i][0];
        int d = points[i][1];
        double len = culculate(a,b,c,d);
        if(confine(len,r))
    {
        result[(*returnSize)]++;
    }
    }
    
    (*returnSize)++;
    }
    return result;
}