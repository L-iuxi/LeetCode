#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    cout << pq.top() << endl;//输出最大值
    //pq.pop();

    int t = pq.top();
    pq.pop();
    pq.push(t+1);//只能修改堆顶值


    return 0;
}