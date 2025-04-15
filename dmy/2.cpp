// 3.（类的组合）我的蛋糕店推出了几个新品：香草蓝莓卷，法式蝴蝶酥，蔓越莓司康和英式红茶，我想相应推出优惠套餐。以下是对这些甜品的具体介绍（这部分已写入前缀）：
// 香草蓝莓卷：每一小块净含量40g左右，热量约为200千卡，定价为9元；
// 法式蝴蝶酥：单个净含量30g左右，热量约为188千卡，定价为15元；
// 蔓越莓司康：单个净含量70g左右，热量约为245千卡，定价为19元；
// 英式红茶：200ml，定价29元，3千卡每100毫升。
// 自由配餐规则：（这部分已写入后缀）选购两种新品及以上时可享受，两种新品享受9折优惠，三种新品享受8折优惠，四种新品享受7折优惠，我需要你输出套餐价格以及净含量和总热量。

// 示例输入1：
// 1 3 0 1
// 示例输出1：
// 该自配餐的价钱为：66.4元;净含量为：330克;热量为：770千卡。
// 展示完毕。

// 示例输入2：
// 0,0,4,0
// 示例输出2：
// 该自配餐的价钱为：76元;净含量为：280克;热量为：980千卡。
// 展示完毕。

// 示例输入3：
// 1,1,1,1
// 示例输出3：
// 该自配餐的价钱为：50.4元;净含量为：340克;热量为：639千卡。
// 展示完毕。
// 前缀代码：
//StudybarCommentBegin
#include<iostream>
using namespace std;
class BlueberryRoll{//香草蓝莓卷 
private:
	int quantity;
	int content;
	int calorie;
	int price;	
public:
	BlueberryRoll(int n){
	quantity=n;
	content=40*n;
	calorie=200*n;
	price=9*n;
	}
	int getquantity(){return quantity;}
	int getcontent(){return content;}
	int getcalorie(){return calorie;}
	int getprice(){return price;}
}; 
class ButterflyCookie{//法式蝴蝶酥 
private:
	int quantity;
	int content;
	int calorie;
	int price;	
public:
	ButterflyCookie(int n){
	quantity=n;
	content=30*n;
	calorie=188*n;
	price=15*n;
	}
	int getquantity(){return quantity;}
	int getcontent(){return content;}
	int getcalorie(){return calorie;}
	int getprice(){return price;}
};
class CranberryScone{//蔓越莓司康 
private:
	int quantity;
	int content;
	int calorie;
	int price;		
public:
	CranberryScone(int n){
	quantity=n;
	content=70*n;
	calorie=245*n;
	price=19*n;
	}
	int getquantity(){return quantity;}
	int getcontent(){return content;}
	int getcalorie(){return calorie;}
	int getprice(){return price;}
};
class BlackTea{//英式红茶 
private:
	int quantity;
	int content;
	int calorie;
	int price;	
public:
	BlackTea(int n){
	quantity=n;
	content=200*n;
	calorie=3*2*n;
	price=29*n;
	}
	int getquantity(){return quantity;}
	int getcontent(){return content;}
	int getcalorie(){return calorie;}
	int getprice(){return price;}
};
class SetMeal{
private:
	BlueberryRoll br;
	ButterflyCookie bc;
	CranberryScone cs;
	BlackTea bt;
	public:
	SetMeal(int blueberryRoll, int butterflyCookie, int cranberryScone, int blackTea)
	: br(blueberryRoll), bc(butterflyCookie), cs(cranberryScone), bt(blackTea) {}

	double gettotalprice() {
        double totalPrice = br.getprice() + bc.getprice() + cs.getprice() + bt.getprice();
        int itemCount = (br.getquantity() > 0) + (bc.getquantity() > 0) + (cs.getquantity() > 0) + (bt.getquantity() > 0);

	  if (itemCount == 2) {
		totalPrice *= 0.9;  
	} else if (itemCount == 3) {
		totalPrice *= 0.8;  
	} else if (itemCount == 4) {
		totalPrice *= 0.7; 
	}

	return totalPrice;
}


int gettotalcontent() {
	return br.getcontent() + bc.getcontent() + cs.getcontent() + bt.getcontent();
}
int gettotalcalorie() {
	return br.getcalorie() + bc.getcalorie() + cs.getcalorie() + bt.getcalorie();
}

};
int main()
{
	int blueberryRoll, butterflyCookie, cranberryScone, blackTea;
    cin >> blueberryRoll >> butterflyCookie >> cranberryScone >> blackTea;

    SetMeal meal(blueberryRoll, butterflyCookie, cranberryScone, blackTea);

	cout << "该自配餐的价钱为：" << meal.gettotalprice() << "元;净含量为：" << meal.gettotalcontent() << "克;热量为：" << meal.gettotalcalorie() << "千卡。" << endl;
    cout << "展示完毕。" << endl;
	

}
