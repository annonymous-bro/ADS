#include <iostream>
#include <vector> 
using namespace std; 
const int N = 5;
bool isSafe(int x, int y, const vector<vector<int>>& maze) {

return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);

}

bool solveMazeUtil(int x, int y, const vector<vector<int>>& maze, vector<vector<int>>& sol) { if (x == N - 1 && y == N - 1) {
sol[x][y] = 1; return true;
}

if (isSafe(x, y, maze)) {

sol[x][y] = 1;

if (solveMazeUtil(x + 1, y, maze, sol) || solveMazeUtil(x, y + 1, maze, sol)) return true;
sol[x][y] = 0; // Backtrack

}

return false; }

void solveMaze(const vector<vector<int>>& maze) { vector<vector<int>> sol(N, vector<int>(N, 0));
if (solveMazeUtil(0, 0, maze, sol)) { cout << "Solution exists. Path:\n"; for (int i = 0; i < N; ++i) {
for (int j = 0; j < N; ++j) cout << sol[i][j] << " ";
cout << endl;	}

} else {

cout << "No solution exists." << endl;	} } int main() {
vector<vector<int>> maze = {{1, 0, 0, 0, 0},

{1, 1, 0, 1, 0},

{0, 1, 0, 0, 0},

{1, 1, 1, 1, 1},

{0, 1, 0, 0, 1}};

solveMaze(maze); return 0;
}




