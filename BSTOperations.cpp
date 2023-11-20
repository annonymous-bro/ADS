#include <iostream> using namespace std;

// Node structure for BST struct Node {
int data; Node* left; Node* right;
Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into BST Node* insert(Node* root, int key) {
if (root == nullptr) { return new Node(key);
}

if (key < root->data) {
root->left = insert(root->left, key);
} else if (key > root->data) {
root->right = insert(root->right, key);
}

return root;
}
 
// Function to find the node with minimum key value in a BST Node* minValueNode(Node* node) {
Node* current = node;
while (current->left != nullptr) { current = current->left;
}
return current;
}

// Function to delete a key from BST Node* deleteNode(Node* root, int key) {
if (root == nullptr) { return root;
}

if (key < root->data) {
root->left = deleteNode(root->left, key);
} else if (key > root->data) {
root->right = deleteNode(root->right, key);
} else {
if (root->left == nullptr) { Node* temp = root->right; delete root;
return temp;
} else if (root->right == nullptr) { Node* temp = root->left; delete root;
return temp;
}

Node* temp = minValueNode(root->right); root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}

// Function to calculate the height of a BST int treeHeight(Node* root) {
if (root == nullptr) { return 0;
} else {
int leftHeight = treeHeight(root->left); int rightHeight = treeHeight(root->right);

return max(leftHeight, rightHeight) + 1;
}
}

// Function to print inorder traversal of BST void inorderTraversal(Node* root) {
if (root != nullptr) { inorderTraversal(root->left); cout << root->data << " "; inorderTraversal(root->right);
}
}

int main() {
Node* root = nullptr;

// Insertion
int keys[] = {50, 30, 70, 20, 40, 60, 80};
for (int key : keys) {
root = insert(root, key);
}

cout << "Inorder Traversal after Insertion: "; inorderTraversal(root);
cout << endl;

// Deletion
root = deleteNode(root, 30);
cout << "Inorder Traversal after Deletion: "; inorderTraversal(root);
cout << endl;

// Height Calculation
cout << "Height of the BST: " << treeHeight(root) << endl;

return 0;
}
