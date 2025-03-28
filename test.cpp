#include <iostream>
#include <string>
//#include <stdio.h>
using namespace std;

class test{
    public:
    int a;
//    test()
//    {
//     cout << "222" <<endl;
//    }
//      test(const test& t)
//      {
//         cout << "111" << endl;
//      }
//      ~test();
void func(int a)
{
    this->a = a;
}
};
// test :: ~test()
// {
//     cout << "333" << endl;
// } 

int main()
{
    test t;
    t.func(10);
    cout << t.a << endl;
    //test b = a;


}