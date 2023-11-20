#include <iostream> #include <vector>

using namespace std;

// Function to calculate the probability of successful search using binary search double probabilityOfSuccessfulSearch(const vector<int>& sortedArray, int target) {
int low = 0;
int high = sortedArray.size() - 1; int index = -1;

// Binary search to find the target while (low <= high) {
int mid = low + (high - low) / 2;

if (sortedArray[mid] == target) { index = mid;
break;
} else if (sortedArray[mid] < target) { low = mid + 1;
} else {
high = mid - 1;
}
}

// Calculate probability if (index != -1) {
return 1.0 / (index + 1);
} else {
return 0.0;
}
}

// Main function for Probability of Successful Search int main() {
vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; int target = 7;

// Calculate probability
double probability = probabilityOfSuccessfulSearch(sortedArray, target);

// Display result
cout << "Sorted Array: "; for (int num : sortedArray) {
cout << num << " ";
}
cout << endl;

cout << "Target: " << target << endl;
cout << "Probability of Successful Search: " << probability << endl;

return 0;
}
