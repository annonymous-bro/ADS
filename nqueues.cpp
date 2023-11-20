// Implementation of N queues in an array

#include <iostream> #include <vector>

using namespace std;

class NQueues { private:
int numQueues; int capacity; vector<int> arr; vector<int> front; vector<int> rear; vector<int> size;

public:
NQueues(int n, int capacity) : numQueues(n), capacity(capacity) { arr.resize(numQueues * capacity);
front.resize(numQueues, -1);
rear.resize(numQueues, -1);
size.resize(numQueues, 0);
}

void enqueue(int queueNum, int data) { if (size[queueNum] == capacity) {
cout << "Queue " << queueNum << " is full. Cannot enqueue " << data << endl; return;
}

if (front[queueNum] == -1) {
front[queueNum] = rear[queueNum] = queueNum * capacity;
} else {
rear[queueNum] = (rear[queueNum] + 1) % (numQueues * capacity);
}

arr[rear[queueNum]] = data; size[queueNum]++;
}

int dequeue(int queueNum) { if (size[queueNum] == 0) {
cout << "Queue " << queueNum << " is empty. Cannot dequeue." << endl; return -1;
}

int data = arr[front[queueNum]];
if (front[queueNum] == rear[queueNum]) { front[queueNum] = rear[queueNum] = -1;
} else {
front[queueNum] = (front[queueNum] + 1) % (numQueues * capacity);
}

size[queueNum]--; return data;
}
};

int main() {
NQueues nq(3, 5);

nq.enqueue(0, 1);
nq.enqueue(0, 2);
nq.enqueue(1, 3);
nq.enqueue(1, 4);
nq.enqueue(2, 5);

cout << nq.dequeue(0) << endl; cout << nq.dequeue(1) << endl; cout << nq.dequeue(2) << endl;

return 0;
}
