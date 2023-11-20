
#include <iostream> #include <vector> using namespace std; class NStacks {
int* arr; int* top; int* next;
int size, k, free;

public:

NStacks(int n, int k) { size = n;
this->k = k;

arr = new int[size]; top = new int[k]; next = new int[size];
for (int i = 0; i < k; ++i)
top[i] = -1;

free = 0;

for (int i = 0; i < size - 1; ++i) next[i] = i + 1;
next[size - 1] = -1;

}

void push(int stackNum, int value) { if (free == -1) {
cout << "Stack Overflow for Stack " << stackNum << endl; return;
}

int i = free; free = next[i];
next[i] = top[stackNum]; top[stackNum] = i;
arr[i] = value;

cout << "Pushed into Stack " << stackNum << ": " << value << endl;	} int pop(int stackNum) {
if (top[stackNum] == -1) {

cout << "Stack " << stackNum << " is empty." << endl; return -1;	}
int i = top[stackNum]; top[stackNum] = next[i]; next[i] = free;
free = i;

int value = arr[i];

cout << "Popped from Stack " << stackNum << ": " << value << endl; return value;
}

};

int main() {

int n = 10, k = 3; NStacks nStacks(n, k); nStacks.push(0, 15);
nStacks.push(1, 45);

nStacks.push(2, 17); nStacks.pop(0); nStacks.pop(1); nStacks.pop(2); return 0;
}
