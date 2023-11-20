#include <iostream> #include <queue>

using namespace std;

class StackUsingQueue { private:
queue<int> q1; queue<int> q2;

public:
void push(int data) { q2.push(data); while (!q1.empty()) {
q2.push(q1.front()); q1.pop();
}
swap(q1, q2);
}

int pop() {
if (q1.empty()) {
cout << "Stack is empty. Cannot pop." << endl; return -1;
}
int data = q1.front(); q1.pop();
return data;
}
};

int main() { StackUsingQueue s;

s.push(1);
s.push(2);
s.push(3);

cout << s.pop() << endl; cout << s.pop() << endl; cout << s.pop() << endl;

return 0;
}
