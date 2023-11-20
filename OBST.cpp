#include <iostream> #include <vector>
#include <limits> // Include the necessary header file

void constructOBST(const std::vector<double>& keys, const std::vector<double>& frequencies, int n) { std::vector<std::vector<double>> cost(n + 1, std::vector<double>(n + 1, 0.0));

for (int i = 1; i <= n; ++i) cost[i][i] = frequencies[i - 1];

for (int L = 2; L <= n; ++L) {
for (int i = 1; i <= n - L + 1; ++i) { int j = i + L - 1;
cost[i][j] = std::numeric_limits<double>::infinity(); // Update here

double p = 0;
for (int k = i; k <= j; ++k) p += frequencies[k - 1];

for (int r = i; r <= j; ++r) {
double c = ((r > i) ? cost[i][r - 1] : 0) +
((r < j) ? cost[r + 1][j] : 0) + p;

if (c < cost[i][j])
cost[i][j] = c;
}
}
}

std::cout << "Optimal Binary Search Tree Cost Table:\n"; for (int i = 1; i <= n; ++i) {
for (int j = 1; j <= n; ++j) {
if (cost[i][j] == std::numeric_limits<double>::infinity()) std::cout << "INF ";
else
std::cout << cost[i][j] << " ";
}
std::cout << std::endl;
}
}

int main() {
std::vector<double> keys = {10, 12, 20};
std::vector<double> frequencies = {0.34, 0.33, 0.33}; int n = keys.size();
constructOBST(keys, frequencies, n);

return 0;
}

