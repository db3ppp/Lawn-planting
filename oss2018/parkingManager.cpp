//C++ camp 주차관리 프로그램
//incomplete
//inheritance 구현 x

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

 class Vehicle{
   public:
   time_t insecond,outsecond;
   int number;
   int fee;
   int type;

   public:
  void setFee(int num) {
    fee = num;
  }
  int getFee(){
    return fee;
  }


 };
class Car : public Vehicle{
  
  public :
  Car(int carnumber, time_t second, int cartype){
  number = carnumber;
  insecond = second;
  outsecond = 0;
  type = cartype;
  }

};


class ParkingLot{
  vector <Car> c;
  int totalFee;
  
  public :
  void init();
  void run();
  void inparking();
  void outparking(vector<Car> &c);
  void showparking(vector<Car> &c);
  void printTotal();
  string timeToString(time_t t);
  int calcFee(time_t insecond, time_t outsecond);
  int calcTime();
  void calcTotalFee();
};

void ParkingLot :: init(){
  totalFee = 0;
}

void ParkingLot :: run(){
  int menu;
  
  while(1){
    cout << "\n1. 입차 2. 출차 3. 주차차량 보기 4. 총 수입 계산하기\n";
		cout << "위 메뉴 중에서 하나를 선택하시오.(0:종료) ------> ";
		cin >> menu;
    
    switch(menu){
      case 0: cout << "종료합니다.\n";
			exit(0);
			case 1: inparking();
			  break;
		 	case 2: outparking(c);
		 	  break;
		 	case 3: showparking(c);
		 	  break;
      case 4: calcTotalFee();
    }
  }
  
}

void ParkingLot :: inparking(){
  int carType, carNum;
  cout << "[입차] 차량종류는? (1.승용, 2.버스, 3.트럭) >>> ";
  cin >> carType;
  cout << "[입차] 차량번호는? >>> ";
  cin >> carNum;
  
  time_t insecond = calcTime();
  string inTime = timeToString(insecond);

  cout <<"["<< carNum<<"] 입차: " << inTime <<endl;

  //객체생성 및 벡터에 넣기
  Car new_car(carNum, insecond, carType);
  c.push_back(new_car);
}

void ParkingLot:: outparking(vector<Car> &c){
  
  int carNum;
  cout << "[출차] 차량번호는? >>> ";
  cin >> carNum;
  
  //벡터에서 차량번호 같은 차 찾기
  //if(find(c.begin(), c.end(), carNum) != c.end()){
  for(int i=0; i< c.size(); i++){
    if(c[i].number == carNum){
      
      time_t outsecond = calcTime();
      string outTime = timeToString(outsecond);
      //c.insert(c[i].outsecond, outsecond);
      c[i].outsecond = outsecond;

      cout <<"["<< carNum<<"] 출차: " << outTime <<endl;    
      c[i].setFee(calcFee(c[i].insecond, c[i].outsecond));
      cout << "요금: " << c[i].getFee() <<endl;

      totalFee += c[i].getFee();
      c.erase(c.begin()+i); //c.erase(c.at(i));
      break;
    } else {
    cout << "존재하는 차량번호가 없습니다." <<endl;
    }
  }
}

void ParkingLot:: showparking(vector<Car> &c){
  cout << "\n==현재 주차현황==\n";
  string inTime;
  string carType;

  for(int i=0;i<c.size();i++){
    inTime = timeToString(c[i].insecond);

    if(c[i].type == 1) carType = "승용";
    else if(c[i].type == 2) carType = "버스";
    else  carType = "트럭";

    cout <<"["<< c[i].number<<"]" << "["<<carType<<"]"<<"입차시간: " << inTime <<endl;
  }
}

int ParkingLot::calcFee(time_t insecond, time_t outsecond){
  int fee;
  int timeGap = (outsecond - insecond);

  if(timeGap>0 && timeGap <= 5){
    fee = 1000;
    cout << "fee test 1 : " << fee << endl;
  } else{
    fee = 1000 + ((timeGap-5) / 10) * 500;
    cout << "fee test 2 : " << fee << endl;
  }
  return fee;
}

void ParkingLot::calcTotalFee(){
  cout << "전체 수익은 "<< totalFee <<"입니다."<<endl;
}


// 현재시간을 string type으로 return하는 함수
string ParkingLot:: timeToString(time_t t){
  struct tm * tstruct;
  char str[80];
  tstruct = localtime(&t);
  strftime(str, sizeof(str), "[%Y-%m-%d] %X", tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링
  return str;
}
int ParkingLot:: calcTime(){
  time_t second;
  second = time(0);
  string time = timeToString(second);
  return second;
}

int main() {
  
  ParkingLot manager;
  manager.init();
  manager.run();

}

