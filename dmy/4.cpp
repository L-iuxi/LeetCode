// 5.（友元·友元类的定义、声明和使用场景）蛋糕店的烘培供应商部分商品平时的价格是这样的：草莓每千克23元，奶油每千克52元，面粉每千克14元，（这部分已写入前缀），但有时会在此基础上变化。蛋糕店新上的草莓拿破仑酥，
// 每个需要草莓0.4千克，奶油0.3千克，面粉0.2千克（这部分已写入后缀）。若每个草莓拿破仑酥售价79元，请帮我计算本月本品的利润，我会先后提供给你供应商本月价格的变动率和草莓拿破仑酥的月销量。另外，为了方便我后续添加单品，
// 我希望你用类将每个单品封装。

// 示例输入1：
// 2 496
// 示例输出1：
// 本月草莓拿破仑酥的利润是：11804.8元

// 示例输入2：
// 1.3 427
// 实例输出2：
// 本月草莓拿破仑酥的利润是：18412.2元

// 示例输入3：
// 0.98 519
// 实例输出3：
// 本月草莓拿破仑酥的利润是：26963.1元

// 前缀代码：
//StudybarCommentBegin
#include<iostream>
using namespace std;
class Supplier{
private:
	double strawberry;
	double cream;
	double flour;
public:
	Supplier(double rate){
		strawberry=23*rate;
		cream=52*rate;
		flour=14*rate;
	}
    friend class Napoleon;
};
//StudybarCommentEnd
//后缀代码：
//StudybarCommentBegin
class Napoleon{
private:
	double cost;
	int amount;
	double totalprofit;
public:
	Napoleon(Supplier f,int n){
		amount=n;
		cost=f.strawberry*0.4+f.cream*0.3+f.flour*0.2;
	}
	void show(){
		totalprofit=(79-cost)*amount;
		cout<<"本月草莓拿破仑酥的利润是："<<totalprofit<<"元"<<endl;
	}
};
int main(){
	double rate;
	int amount;
	cin>>rate>>amount;
	Supplier supplier(rate);
	Napoleon napoleon(supplier,amount);
	napoleon.show();
}
//StudybarCommentEnd