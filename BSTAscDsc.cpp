#include <algorithm> // For std::reverse #include <vector>
#include <iostream> using namespace std;

struct Node { int data; Node* left; Node* right;

Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root) { if (root) {
inorderTraversal(root->left); cout << root->data << " "; inorderTraversal(root->right);
}
}

Node* sortedArrayToBST(vector<int>& arr, int start, int end) { if (start > end) {
return nullptr;
}

int mid = (start + end) / 2;
Node* root = new Node(arr[mid]);

root->left = sortedArrayToBST(arr, start, mid - 1); root->right = sortedArrayToBST(arr, mid + 1, end);

return root;
}

int main() {
vector<int> ascendingArray = {20, 30, 40, 50, 60, 70, 80};
vector<int> descendingArray = {80, 70, 60, 50, 40, 30, 20};

Node* ascendingRoot = sortedArrayToBST(ascendingArray, 0, ascendingArray.size() - 1); cout << "Inorder Traversal of BST from Ascending Order Array: "; inorderTraversal(ascendingRoot);
cout << endl;

reverse(descendingArray.begin(), descendingArray.end());
Node* descendingRoot = sortedArrayToBST(descendingArray, 0, descendingArray.size() - 1); cout << "Inorder Traversal of BST from Descending Order Array: "; inorderTraversal(descendingRoot);
cout << endl;

return 0;
}

