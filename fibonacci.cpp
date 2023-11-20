#include <iostream> #include <vector>

using namespace std;

int fibonacciSearch(const vector<int>& arr, int key) { int n = arr.size();

// Initialize Fibonacci numbers
int fibM2 = 0; // (m-2)'th Fibonacci number int fibM1 = 1; // (m-1)'th Fibonacci number
int fib = fibM2 + fibM1; // m'th Fibonacci number

// Find the smallest Fibonacci number greater than or equal to n while (fib < n) {
fibM2 = fibM1; fibM1 = fib;
fib = fibM1 + fibM2;
}
int offset = -1; // Offset used to keep track of the eliminated range while (fib > 1) {
int i = min(offset + fibM2, n - 1);

if (arr[i] < key) { fib = fibM1; fibM1 = fibM2;
fibM2 = fib - fibM1; offset = i;
} else if (arr[i] > key) { fib = fibM2;
fibM1 = fibM1 - fibM2; fibM2 = fib - fibM1;
} else {
return i; // Key found
}
}

if (fibM1 && arr[offset + 1] == key) { return offset + 1; // Key found
}

return -1; // Key not found
}

int main() {
vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
int key = 85;
int result = fibonacciSearch(arr, key); if (result != -1)
cout << "Element found at index " << result << endl; else
cout << "Element not found in the array" << endl;

return 0;
}
