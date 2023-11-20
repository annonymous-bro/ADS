#include <iostream> #include <vector> #include <string>

using namespace std;

// Compute LPS array for the pattern vector<int> computeLPS(const string& pat) {
int m = pat.length(); vector<int> lps(m, 0);
int len = 0; // Length of the previous longest prefix suffix

for (int i = 1; i < m; i++) {
while (len > 0 && pat[i] != pat[len]) len = lps[len - 1];

if (pat[i] == pat[len]) len++;

lps[i] = len;
}

return lps;
}

// KMP String Searching Algorithm
void KMP(const string& txt, const string& pat) { int n = txt.length();
int m = pat.length();
vector<int> lps = computeLPS(pat); int i = 0; // Index for txt
int j = 0; // Index for pat while (i < n) {
if (pat[j] == txt[i]) { j++;
i++;
}

if (j == m) {
cout << "Pattern found at index " << i - j << endl; j = lps[j - 1];
} else if (i < n && pat[j] != txt[i]) { if (j != 0)
j = lps[j - 1]; else
i++;
}
}
}

// Main Function for KMP Algorithm int main() {
string txt = "ABABDABACDABABCABAB";
string pat = "ABABCABAB"; KMP(txt, pat);
return 0;
}
