// 6.我的蛋糕店新上了一款草莓可露丽，需要100g低筋面粉、50g奶油、120g细砂糖、300g牛奶、40g草莓，
// 这样的一个草莓可露丽售价59元。牛奶平时的价格是每千克65元，细砂糖则是每千克41元。请你将刚写过的代码用继
// 承的方式改写，并添加单品草莓可露丽，请帮我计算本月这两个单品的利润，我会先后提供给你供应商本月价格的变动
// 率、草莓拿破仑酥和草莓可露丽的月销量。

// 示例输入1：
// 2 429 317
// 示例输出1：
// 本月草莓拿破仑酥的利润是：10210.2元
// 本月草莓可露丽的利润是：101.44元

// 示例输入2：
// 1.1 399 420
// 示例输出2：
// 本月草莓拿破仑酥的利润是：20508.6元
// 本月草莓可露丽的利润是：12457.2元

// 示例输入3：
// 0.79 279 371
// 示例输出3：
// 本月草莓拿破仑酥的利润是：22041元
// 本月草莓可露丽的利润是：21889元

// 前缀代码：
//StudybarCommentBegin
#include<iostream>
using namespace std;
class Supplier{
private:
	double strawberry;
	double cream;
	double flour;
	double milk;
	double sugar;
public:
	Supplier(double rate){
		strawberry=23*rate;
		cream=52*rate;
		flour=14*rate;
		milk=65*rate;
		sugar=41*rate; 
	}
	double getNapoleon(){
		return strawberry*0.4+cream*0.3+flour*0.2;
	}
	double getCanele(){
		return strawberry*0.04+cream*0.05+flour*0.1+milk*0.3+sugar*0.12;
	}
}; 
class Napoleon : public Supplier {
    private:
        double cost;        
        int amount;         
        double totalprofit; 
    public:
       
        Napoleon(int amount, double rate) : Supplier(rate), amount(amount) {
            cost = getNapoleon(); 
        }
    
       
        void show() {
            totalprofit = (79 - cost) * amount;  
            cout << "本月草莓拿破仑酥的利润是：" << totalprofit << "元" << endl;
        }
    };

// 后缀代码：
//StudybarCommentBegin
class Canele : public Supplier {
    private:
        double cost;       
        int amount;         
        double totalprofit; 
    public:
        
        Canele(int amount, double rate) : Supplier(rate), amount(amount) {
            cost = getCanele();  
        }
    
        void show() {
            totalprofit = (59 - cost) * amount;  
            cout << "本月草莓可露丽的利润是：" << totalprofit << "元" << endl;
        }
    };
int main(){
	double rate;
	int amount1,amount2;
	cin>>rate>>amount1>>amount2;
	Napoleon napoleon(amount1,rate);
	Canele canele(amount2,rate);
	napoleon.show();
	canele.show();
}
//StudybarCommentEnd