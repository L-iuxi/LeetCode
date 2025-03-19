#include <iostream>
#include <math.h>
using namespace std;

class Cakebase{
    void setgrades(double r,double h,int before,int after)
    {
        double br = 3.14 * r * r * h;
        br = br / (double)after;
    
     if(br > 5.0){
        point -= (br - 5.0) / 0.5;
    }else if(br < 3.5)
    {
        point -= (3.5 - br) / 0.5;
    }
    //cout << "br的得分是" << br << endl;
    int ss;
    ss = (before - after) * 1000000/ before;
    double temp;
    if(ss > 150000)
    {
         temp = ((double)ss-150000.0) / 20000.0;
        point -= temp;
    }else if(ss < 100000)
    {
         temp = (100000.0 - (double)ss) / 20000.0;
         point -= temp;
    }

    //cout << "ss的得分是" << temp << endl;
    }
    public:
    double r;
    double h;
    int before;
    int after;
    double point = 10.00;
    void setcake(double a,double b,int c,int d)
    {
        r = a;
        h = b;
        before = c;
        after = d;
        setgrades(r,h,before,after);
    }
    void showgrade()
    {

        cout << "cake的得分是" << point << endl;
    }

};
int main()
{
    Cakebase cake1,cake2,cake3;
    cake1.setcake(7.5,5,600,500);
    cake1.showgrade();
    cake2.setcake(10,8,1200,1000);
    cake2.showgrade();
    cake3.setcake(15,11,2400,2219);
    cake3.showgrade();
    return 0;
}