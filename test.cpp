#include <iostream>
#include <string>
//#include <stdio.h>
using namespace std;

class test{
    public:
   int a;
   test()
   {
    cout << "222" <<endl;
   }
     test(const test& t)
     {
        cout << "111" << endl;
     }
};

int main()
{
    test a;
    test b = a;


}