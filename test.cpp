#include <iostream>
#include <string>

using namespace std;

class test{
    public:
    int a;
    test();
 };
 test :: test() :a(0)
 {
    cout << a << endl;
 }

int main()
{
   test t;



}