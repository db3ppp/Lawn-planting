/* C++ stack_array */

#include <iostream>
#define SIZE 100
using namespace std;

class Stack{
  private:
  int s[SIZE];
  int top;

  public :
    void init();//stack initialization
    void print();//stack status print
    void push(int x);
    int pop();
    bool isempty();
    bool isfull();
};

int main(){
  int input, output;
  Stack stack;
  int choose;
  
  stack.init();

  while(1){
  cout<<"어떤 명령을 실행하시겠습니까?(1.push 2.pop 3.print 4.exit)";
  cin>>choose;
  
  switch(choose){

    case 1: if(stack.isfull()==true)
              cout<<"stack is full!\n";
            else{
              cout<<"push할 숫자입력\n";
              cin >> input;
              stack.push(input);
            }
              break;
    case 2: if(stack.isempty()==true)
              cout<<"stack is empty!\n";
            else{
            output = stack.pop();
            cout <<"pop한 값은"<<output<<"입니다.\n";
            }
            break;
    case 3: stack.print();
            break;
    case 4: break;
    default: cout<<"올바른 명령을 선택하세요\n";
  }
    if (choose == 4) {
          cout<<"exit";
           break;
    }
  }

}

void Stack :: init(){
  top = 0;
}

bool Stack :: isempty(){
  if(top == 0)
  return true;
  else return false;
}
bool Stack :: isfull(){
  if(top == SIZE)
  return true;
  else return false;
}

void Stack :: push(int x){
    s[top] = x;
    top++;
}

int Stack :: pop(){
    top--;
  
  return s[top];
}

void Stack :: print(){
  cout<<"\n***print stack***\n";
  for(int i=0; i<top;i++){
    cout<<"["<<i<<"] "<<s[i]<<endl;
  }

}
