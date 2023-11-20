#include <iostream> #include <stack>

using namespace std;

class QueueUsingStack { private:
stack<int> enqueueStack; stack<int> dequeueStack;

public:
void add(int data) { enqueueStack.push(data);
}

int remove() {
if (dequeueStack.empty()) {
if (enqueueStack.empty()) {
cout << "Queue is empty. Cannot remove." << endl; return -1;
}
while (!enqueueStack.empty()) { dequeueStack.push(enqueueStack.top()); enqueueStack.pop();
}
}
int data = dequeueStack.top(); dequeueStack.pop();
return data;
}
};

int main() { QueueUsingStack q;

q.add(1);
q.add(2);
q.add(3);

cout << q.remove() << endl;
 
cout << q.remove() << endl; cout << q.remove() << endl;

return 0;
}
