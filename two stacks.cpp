#include <iostream>

using namespace std;
class TwoStacks {
  int * arr;
  int size;
  int top1, top2;

  public:

    TwoStacks(int n) {
      size = n;
      arr = new int[n];
      top1 = -1;
      top2 = size;

    }

  void push1(int value) {
    if (top1 < top2 - 1) {
      arr[++top1] = value;
      cout << "Pushed into Stack 1: " << value << endl;

    } else {

      cout << "Stack Overflow for Stack 1." << endl;

    }
  }

  void push2(int value) {
    if (top1 < top2 - 1) {
      arr[--top2] = value;
      cout << "Pushed into Stack 2: " << value << endl;

    } else {

      cout << "Stack Overflow for Stack 2." << endl;

    }
  }

  int pop1() {

    if (top1 >= 0) {

      int value = arr[top1--];

      cout << "Popped from Stack 1: " << value << endl;
      return value;
    } else {

      cout << "Stack 1 is empty." << endl;
      return -1;
    }
  }

  int pop2() {

    if (top2 < size) {

      int value = arr[top2++];

      cout << "Popped from Stack 2: " << value << endl;
      return value;

    } else {

      cout << "Stack 2 is empty." << endl;
      return -1;
    }
  }

};

int main() {

  TwoStacks ts(5);
  ts.push1(5);
  ts.push2(10);

  ts.push2(15);

  ts.push1(11);

  ts.push2(7);

  ts.pop1();

  ts.pop2();
  return 0;
}
