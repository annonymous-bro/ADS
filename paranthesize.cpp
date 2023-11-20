#include <iostream> #include <vector> #include <limits>

// Function to find optimal parenthesization for matrix multiplication
void matrixChainOrder(const std::vector<int>& dimensions, std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& s) {
int n = dimensions.size() - 1; // Number of matrices for (int len = 2; len <= n; ++len) {
for (int i = 1; i <= n - len + 1; ++i) { int j = i + len - 1;
m[i][j] = std::numeric_limits<int>::max(); for (int k = i; k < j; ++k) {
int cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j]; if (cost < m[i][j]) {
m[i][j] = cost;
s[i][j] = k;
}
}
}
}
}

// Function to print optimal parenthesization
void printOptimalParenthesis(const std::vector<std::vector<int>>& s, int i, int j) { if (i == j) {
std::cout << "A" << i;
} else {
std::cout << "("; printOptimalParenthesis(s, i, s[i][j]); printOptimalParenthesis(s, s[i][j] + 1, j); std::cout << ")";
}
}

int main() {
// Example usage
std::vector<int> dimensions = {30, 35, 15, 5, 10, 20, 25}; int n = dimensions.size() - 1;

std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1, 0));
std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1, 0));

matrixChainOrder(dimensions, m, s);

std::cout << "Optimal Parenthesization: "; printOptimalParenthesis(s, 1, n); std::cout << std::endl;

return 0;
}

