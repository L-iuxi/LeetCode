#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;


int main()
{
   vector<int> arr= {3,6,7,1,5};
   //vector<vector<int>>arr(n,vector<int> (m));//二维数组,n行m列，每行有m个元素
   arr.push_back(100);
   arr.pop_back();
   sort(arr.begin(),arr.end());
   //arr.resize(7,3);
   // for(int i = 0;i < arr.size();i++)
   // {
   //    cout << arr[i] << endl;
   // }
   for(vector<int>:: iterator it = arr.begin();it != arr.end();it++)
   {
      //cout << *it << endl;
   }//arr.rbegin(),arr.rend()反向遍历
   //arr.clear();//清空
  // arr.empty();//判空
   
  int pos = lower_bound(arr.begin(),arr.end(),7) - arr.begin();
  cout << pos << endl;
  reverse(arr.begin(),arr.end());
  for(int i = 0;i < arr.size();i++)
   {
      cout << arr[i] << endl;
   }

return 0;
}