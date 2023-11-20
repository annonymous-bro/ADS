#include <iostream> #include <vector>

// Function to perform matrix multiplication for two matrices
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
int rowsA = A.size(); int colsA = A[0].size(); int rowsB = B.size(); int colsB = B[0].size();

// Check if the matrices can be multiplied if (colsA != rowsB) {
std::cerr << "Matrices cannot be multiplied. Invalid dimensions." << std::endl; return {};
}
std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0)); for (int i = 0; i < rowsA; ++i) {
for (int j = 0; j < colsB; ++j) {
for (int k = 0; k < colsA; ++k) { result[i][j] += A[i][k] * B[k][j];
}
}
}

return result;
}

// Function to perform matrix multiplication for a list of matrices
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<std::vector<int>>>& matrices) {
if (matrices.empty()) {
std::cerr << "No matrices provided." << std::endl; return {};
}
std::vector<std::vector<int>> result = matrices[0]; for (size_t i = 1; i < matrices.size(); ++i) {
result = matrixMultiply(result, matrices[i]);
}

return result;
}

int main() {
// Example usage std::vector<std::vector<std::vector<int>>> matrices = {
{{1, 2}, {3, 4}},
{{5, 6}, {7, 8}},
{{9, 10}, {11, 12}}
};

std::vector<std::vector<int>> result = multiplyMatrices(matrices);

// Display the result
for (const auto& row : result) { for (int elem : row) {
std::cout << elem << " ";
}
std::cout << std::endl;
}

return 0;
}
