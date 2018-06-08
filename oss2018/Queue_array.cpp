/* C++ queue_array */

#include <iostream>
#define SIZE 100
using namespace std;

class Queue{
  private:
  int front;
  int rear;
  int q[SIZE];

  public:
  Queue();//constructor
  void enqueue(int x);
  int dequeue();
  void print();

  bool isempty();
  bool isfull();
};

int main() {
  int input, output;
  Queue queue;
  int choose;
  
  Queue();

  while(1){
  cout<<"어떤 명령을 실행하시겠습니까?(1.enqueue 2.dequeue 3.print 4.exit)";
  cin>>choose;
  
  switch(choose){
    case 1: if(queue.isfull()==true)
            cout<<"queue is full!\n";
            else{
            cout<<"enqueue할 숫자입력\n";
            cin >> input;
            queue.enqueue(input);
            }
            break;
    case 2: if(queue.isempty()==true)
              cout<<"queue is empty!\n";
            else{
            output = queue.dequeue();
            cout <<"dequeue한 값은"<<output<<"입니다.\n";
            }
            break;
    case 3: queue.print();
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
Queue :: Queue(){
  front = 0;
  rear = 0;
}

void Queue :: enqueue(int x){
  q[rear] = x;
  rear++;
}

int Queue :: dequeue(){

  return q[front++];
}

bool Queue :: isempty(){
  if(rear == front) return true;
  else return false;
}
bool Queue :: isfull(){
  if(rear == SIZE) return true;
  else return false;
}

void Queue :: print(){
  cout<<"\n*** print queue ****\n";
  for(int i=front; i<rear ;i++){
    cout<<"["<<i<<"]"<<q[i]<<endl;
  }
}
