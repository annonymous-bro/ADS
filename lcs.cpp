#include <iostream> #include <vector> #include <algorithm>

using namespace std;

int lcs(const string& X, const string& Y) { int m = X.length();
int n = Y.length();

// Create a 2D table to store the lengths of LCS vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

// Fill the table in a bottom-up manner for (int i = 1; i <= m; ++i) {
for (int j = 1; j <= n; ++j) { if (X[i - 1] == Y[j - 1])
dp[i][j] = dp[i - 1][j - 1] + 1; else
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
}

// Length of LCS is stored in dp[m][n] return dp[m][n];
}

int main() {
string X = "AGGTAB"; string Y = "GXTXAYB";

cout << "Length of LCS: " << lcs(X, Y) << endl;

return 0;
}
