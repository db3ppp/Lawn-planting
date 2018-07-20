// 통장관리 프로그램

#include <iostream>
#include <string>
using namespace std;

class MoneyBox{										
private:
	string name;									
	int sum;							
	int grade;
	
public:
	void init(string newname, int money, int newgrade);
	void save(int money);	//예금하기									
	void use(int money);	//출금하기									
	void print();												
	int getsum();		//현재잔고가져오기
	int getGrade();         //현재통장 신용등급 가져오기 
	int transfer(MoneyBox &t, int money); //송금하기
	void calcInt();                       //이자계산하여 통장에 넣어주기 
};

void MoneyBox::init(string newname, int money, int newgrade)
{
	name=newname;
	sum=money;
	grade = newgrade;
}
void MoneyBox::save(int money)
{
	sum+=money;	
}
void MoneyBox::use(int money)
{
  if(grade == 1){
    sum-=money;
  } else{
	    if (money>sum)
		    cout<<"잔고가 부족합니다!\n";
	    else
	    	sum-=money;
   }	
}
void MoneyBox::print()
{
  cout << name << "님의 신용등급은 [" << grade << "]등급입니다.\n";
	cout << name << "님의 예금잔고는 " << sum << "원입니다.\n";
}
int MoneyBox::getsum()
{
	return sum;
}
int MoneyBox::getGrade()
{
  return grade;
}
int MoneyBox::transfer(MoneyBox &t, int money)
{
  if(grade == 1){
    use(money);
    t.save(money);
    return 1;
  } else{
	  if (sum < money)//돈이 충분하지 않으면
		  return 0;
	  else
	  {
	  	use(money);
	  	t.save(money);
		return 1;
	  }
  }
	
}
void MoneyBox::calcInt(){
  float interest, tax;
  
  if(grade == 1){
    interest = sum*0.03;
    sum += interest;
  }
  else if(grade == 2){
    interest = sum*0.02;
    sum += interest;
  }
  else{
    interest = sum*0.01;
    sum += interest;
  }
  tax = interest*0.22;
  sum-=tax;
  cout <<"이자: "<<interest;
  cout <<"세금: "<<tax;
}


int main()
{
	MoneyBox a, b;			//통장 a와 b를 생성
	int key;				
	int howmuch;			//입출금액을 위한 변수

	a.init("Kim", 10000, 1);		
	b.init("Lee", 10000, 3);				
	
	while(1)
	{
		cout << "\n11: Kim 입금 12: Kim 출금 13: Kim 잔고확인 14: Kim의 이자계산 15:Lee에게 송금\n";
		cout << "21: Lee 입금 22: Lee 출금 23: Lee 잔고확인 24: Lee의 이자계산 25: Kim에게 송금 \n";
		cout << "위 메뉴 중에서 하나를 선택하시오.(0:종료) ------> ";
		cin >> key;

		switch(key){
			case 0: 
				cout << "종료합니다.\n";
				return 0;
			case 11: 
				cout << "입금할 금액은? ";
				cin >> howmuch;
				a.save(howmuch);
				break;
			case 12:
				cout << "출금할 금액은? ";
				cin >> howmuch;
				a.use(howmuch);
				break;
			case 13:
				a.print();
				break;
			case 14:
			  cout << "Kim님에게 이자가 지급되었습니다.\n";
			  a.calcInt();
			  break;
			case 15:
				cout << "송금할 금액은? ";
				cin >> howmuch;
				if (a.transfer(b,howmuch) == 0) cout << "송금 실패";
				else cout <<"송금 성공";
				break;
			case 21:
				cout << "입금할 금액은? ";
				cin >> howmuch;
				b.save(howmuch);
				break;
			case 22:
				cout << "출금할 금액은? ";
				cin >> howmuch;
				b.use(howmuch);
				break;
			case 23:
				b.print();
				break;
			case 24:
			  cout << "Lee의 이자는? ";
			  b.calcInt();
			  break;
			 case 25:
			  cout << "송금할 금액은? ";
				cin >> howmuch;
				if (b.transfer(a,howmuch) == 0) cout << "송금 실패";
				else cout <<"송금 성공";
				break;
			default:
				cout << "잘못 입력했습니다. 다시 입력하시오\n";
				break;
		}
	}
	return 0;
}
