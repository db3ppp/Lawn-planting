//C++ camp 과일판매, 구매 프로그램

#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
  string myStore;
  string myfruit;
  
public:
  
	void InitMembers(int price, int num, int money, string store, string fruit)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
		myStore = store;
		myfruit = fruit;
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		
		//덤 기능 추가 
		if(num > 10 ){
		  //공짜니까 판매수익은 내지 않는다. 
		  //myMoney -= (num/10)*APPLE_PRICE;
		  //공짜니까 남은사과 갯수는 줄어든다
		  numOfApples -= (num/10);
		  //구매자가 구매한 사과개수는 추가적으로 증가한다.
		}
		
		if(numOfApples > num){
		numOfApples-=num;
		myMoney+=money;
	  }
	  else cout<<"재고가 없습니다!!"<<endl;
	  
		return num;
	}
	
	int ChangeMoney(int money){
	  int change;
	  if(money % APPLE_PRICE !=0){
	    change = money % APPLE_PRICE;
	  }else change = 0;
	  
	    cout << "거스름돈 "<<change<<" 원입니다."<<endl;
	  return change;
	}
	
	void ShowSalesResult()
	{
	  cout<<endl<<myStore<<"가게 "<<myfruit<< "판매현황"<<endl;
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:
  string myName;
  string myfruit;
  
public:
	void InitMembers(int money,string name, string fruit)
	{
		myMoney=money;
		numOfApples=0;
		myName = name;
		myfruit = fruit;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
	  if(myMoney >= money){
		numOfApples+=seller.SaleApples(money);
		myMoney -= money;
		myMoney += seller.ChangeMoney(money);
	  }else cout << "잔액이 부족합니다!"<<endl;
	  
	  	/*덤 기능 추가 */
		if(numOfApples >= 10 ){
		  numOfApples += (numOfApples/10);
		  //구매자가 구매한 사과개수는 추가적으로 증가한다.
		}
		
	}
	void ShowBuyResult()
	{
	  cout<<endl<<myName<<"의 " <<myfruit<< "구매현황"<<endl;
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	FruitSeller seller2;
	
	seller.InitMembers(1000, 20, 0, "CheaperShop","사과");
	seller2.InitMembers(2000,10,0, "LuxuryShop","복숭아");
	
	FruitBuyer buyer;
	FruitBuyer buyer2;
	buyer.InitMembers(20000,"hyewon","사과");
	buyer2.InitMembers(10000,"혜원이","복숭아");
	
  
	cout<<"<과일 판매자의 현황>"<<endl;
	seller.ShowSalesResult();
	seller2.ShowSalesResult();
	cout<<"<과일 구매자의 현황>"<<endl;
	buyer.ShowBuyResult();
	buyer2.ShowBuyResult();

	buyer.BuyApples(seller, 10000);
	buyer2.BuyApples(seller2, 2000);

	cout<<"<과일 판매자의 현황>"<<endl;
	seller.ShowSalesResult();
	seller2.ShowSalesResult();
	cout<<"<과일 구매자의 현황>"<<endl;
	buyer.ShowBuyResult();
	buyer2.ShowBuyResult();
	
	return 0;
}

