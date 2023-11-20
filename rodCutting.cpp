#include <climits> #include <iostream> #include <vector> #include <algorithm>

using namespace std;

// Naive Recursive Approach
int cutRodNaive(const vector<int>& price, int n) { if (n <= 0)
return 0;

int maxVal = INT_MIN; for (int i = 0; i < n; i++)
maxVal = max(maxVal, price[i] + cutRodNaive(price, n - i - 1));

return maxVal;
}

// Optimized Iterative Approach
int cutRodOptimized(const vector<int>& price, int n) { vector<int> dp(n + 1, 0);

for (int i = 1; i <= n; i++) { int maxVal = INT_MIN; for (int j = 0; j < i; j++)
maxVal = max(maxVal, price[j] + dp[i - j - 1]); dp[i] = maxVal;
}

return dp[n];
}

// Main Function for Rod Cutting Problem int main() {
vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; int n = price.size();

cout << "Naive Approach: " << cutRodNaive(price, n) << endl;
cout << "Optimized Approach: " << cutRodOptimized(price, n) << endl;

return 0;
}
