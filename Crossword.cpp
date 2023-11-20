#include <iostream> #include <vector> using namespace std; const int N = 10;
void printBoard(const vector<vector<char>>& board) { for (int i = 0; i < N; ++i) {
for (int j = 0; j < N; ++j) cout << board[i][j] << " "; cout << endl;
}

}

bool canPlaceWordH(const vector<vector<char>>& board, const string& word, int row, int col) { if (col + word.length() > N)
return false;

for (int j = 0; j < word.length(); ++j) {

if (board[row][col + j] != '-' && board[row][col + j] != word[j]) return false;
 
}

return true;

}

bool placeWordH(vector<vector<char>>& board, const string& word, int row, int col) { vector<char> backup = board[row];
for (int j = 0; j < word.length(); ++j) board[row][col + j] = word[j]; printBoard(board);
board[row] = backup; // Backtrack return true;
}

bool canPlaceWordV(const vector<vector<char>>& board, const string& word, int row, int col) { if (row + word.length() > N)
return false;

for (int i = 0; i < word.length(); ++i) {

if (board[row + i][col] != '-' && board[row + i][col] != word[i]) return false;
}

return true;

}

bool placeWordV(vector<vector<char>>& board, const string& word, int row, int col) { vector<char> backup(N);
for (int i = 0; i < word.length(); ++i) backup[i] = board[row + i][col];
for (int i = 0; i < word.length(); ++i) board[row + i][col] = word[i];
 
printBoard(board);

for (int i = 0; i < word.length(); ++i) board[row + i][col] = backup[i]; // Backtrack return true;
}

bool crossword(vector<vector<char>>& board, vector<string> words, int index) { if (index == words.size()) {
cout << "Crossword Solved!\n"; printBoard(board);
return true;

}

for (int i = 0; i < N; ++i) { for (int j = 0; j < N; ++j) {
if (board[i][j] == '-' || board[i][j] == words[index][0]) {


if (canPlaceWordH(board, words[index], i, j)) { placeWordH(board, words[index], i, j);
if (crossword(board, words, index + 1)) return true;
}


if (canPlaceWordV(board, words[index], i, j)) { placeWordV(board, words[index], i, j);
if (crossword(board, words, index + 1)) return true;
}
}

}

}

return false;

}

int main() {

vector<vector<char>> board = {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},

{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},

{'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},

{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},

{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},

{'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},

{'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},

{'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},

{'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},

{'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};


vector<string> words = {"AGRA", "NORWAY", "ENGLAND", "GWALIOR"};

if (!crossword(board, words, 0)) cout << "No solution exists.\n"; return 0;
}
	

