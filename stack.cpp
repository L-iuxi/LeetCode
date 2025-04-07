#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stk;
    stk.push(2);
    stk.push(3);
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();

    return 0;
}