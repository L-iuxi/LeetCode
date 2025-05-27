#define max(a,b) ((a) > (b) ? (a):(b))
#define min(a,b) ((a) > (b) ? (b):(a))
int maxProfit(int* prices, int pricesSize) {
  int result = 0;
  int min_p = prices[0];
  for(int i = 0;i < pricesSize;i++)
  {
    int p = prices[i];
    result= max(p-min_p,result);
    min_p = min(min_p,p);
  }
  return result;
}