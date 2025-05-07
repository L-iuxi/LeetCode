
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