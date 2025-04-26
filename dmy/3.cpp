// 3.我需要为蛋糕店设置会员系统，首先我需要统计总会员的个数，所有会员消费时都可以享受固定八八折
// 另外还根据其会员积分（1消费额=1积分）享受专属抵扣，最低可抵至八折并扣除相应积分。

// 示例输入（为了方便将三组数据同时输入）：
// 166 98 682 39 177 42
// 示例输出：
// 会员的基本信息如下:
// 剩余积分158
// 本单消费78
// 会员的基本信息如下:
// 剩余积分679
// 本单消费31
// 会员的基本信息如下:
// 剩余积分174
// 本单消费33
// 总会员数:3人

// 前缀代码：
//StudybarCommentBegin
#include<iostream>
using namespace std;

class VIP{
private:
	static int members;
	int points;
	int spending;
public:
	VIP(int a,int b){
		points=a;
		spending=b;
		members++;
	}
   void discount();
   void show(); 
   int getmembers();
};
void VIP :: discount()
{
    int before = spending * 0.88;
    //spending *= 0.88 ;
    int after = spending * 0.8;
    points -= (before - after);
    spending = after;
    //membernums++;
}
void VIP:: show()
{
    cout << "会员的基本信息如下:" << endl <<"剩余积分"<<points<<endl<<"本单消费"<<spending<<endl;
}
int VIP :: getmembers()
{
    return members;
}
int VIP :: members = 0;
//StudybarCommentEnd
// 后缀代码：
//StudybarCommentBegin
int main(){
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	VIP vip1(x1,y1);
	vip1.discount();
	vip1.show();
	VIP vip2(x2,y2);
	vip2.discount();
	vip2.show();
	VIP vip3(x3,y3);
	vip3.discount();
	vip3.show();
	cout<<"总会员数:"<<vip1.getmembers()<<"人"<<endl; 
}
//StudybarCommentEnd