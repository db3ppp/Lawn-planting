//C++ Reference 개념

#include <iostream>
#include <fstream>

using namespace std;

void modify(int& n){ //call by reference
  n = 1000;
}

int main(){
  int num;  // 진짜변수 (변수의 값을 넣는 공간이 있음)
  int* pNum; // 포인터변수 --> 자기는 값이 없고, 뭔가 다른 진짜 정수변수를 가리킴
  int& rNum=num; // 레퍼런스변수 --> 아무것도 아님.. 그저 별명에 불과함

  num=100;
  rNum=200;
  pNum = &num;
  *pNum = 300;

 // modify(num);
 // --> modify(int& n)을 호출.. int& n = num
 // 효과적으로 call by value (value == pointer, reference)

  cout<<"num :"<<num<<endl;
  cout<<"*pNum :"<<*pNum<<endl;
  cout<<"rNum : "<<rNum<<endl;
  //모두 300을 출력
}

