#include <iostream>

using namespace std;

class CircularQueue { private:
int capacity; int* arr;
int front; int rear;

public:
CircularQueue(int size) : capacity(size), front(-1), rear(-1) { arr = new int[capacity];
}

void enqueue(int data) {
if ((rear + 1) % capacity == front) {
cout << "Queue is full. Cannot enqueue " << data << endl; return;
}

if (front == -1) { front = rear = 0;
} else {
rear = (rear + 1) % capacity;
}

arr[rear] = data;
}

int dequeue() {
if (front == -1) {
cout << "Queue is empty. Cannot dequeue." << endl; return -1;
}
int data = arr[front]; if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % capacity;
}

return data;
}
};

int main() { CircularQueue cq(3);

cq.enqueue(1); cq.enqueue(2); cq.enqueue(3); cq.enqueue(4); // Queue is full

cout << cq.dequeue() << endl; cout << cq.dequeue() << endl; cout << cq.dequeue() << endl;
cout << cq.dequeue() << endl; // Queue is empty

return 0;
}
