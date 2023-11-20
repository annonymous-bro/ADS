#include <iostream> #include <algorithm>

struct Node { int key; Node* left; Node* right; int height;
};

int getHeight(Node* node) { if (node == nullptr)
return 0;
return node->height;
}

int getBalanceFactor(Node* node) { if (node == nullptr)
return 0;
return getHeight(node->left) - getHeight(node->right);
}

Node* createNode(int key) { Node* newNode = new Node(); newNode->key = key;
newNode->left = newNode->right = nullptr;
newNode->height = 1; // New node is initially at height 1 return newNode;
}

Node* rightRotate(Node* y) { Node* x = y->left;
Node* T2 = x->right;

// Perform rotation x->right = y;
y->left = T2;

// Update heights
y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1; x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

return x; // New root
}

Node* leftRotate(Node* x) { Node* y = x->right; Node* T2 = y->left;

// Perform rotation y->left = x;
x->right = T2;

// Update heights
x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1; y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

return y; // New root
}

Node* insertNode(Node* root, int key) {
// Perform standard BST insertion if (root == nullptr)
return createNode(key);

if (key < root->key)
root->left = insertNode(root->left, key); else if (key > root->key)
root->right = insertNode(root->right, key); else // Duplicate keys not allowed
return root;

// Update height of current node
root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

// Get the balance factor
int balance = getBalanceFactor(root);

// Left Left Case
if (balance > 1 && key < root->left->key) return rightRotate(root);

// Right Right Case
if (balance < -1 && key > root->right->key) return leftRotate(root);

// Left Right Case
if (balance > 1 && key > root->left->key) {
root->left = leftRotate(root->left); return rightRotate(root);
}

// Right Left Case
if (balance < -1 && key < root->right->key) { root->right = rightRotate(root->right); return leftRotate(root);
}

return root;
}

void inorderTraversal(Node* root) { if (root != nullptr) {
inorderTraversal(root->left); std::cout << root->key << " "; inorderTraversal(root->right);
}
}

// Function to find the node with the minimum key value Node* minValueNode(Node* node) {
Node* current = node;
while (current->left != nullptr) current = current->left;
return current;
}

Node* deleteNode(Node* root, int key) { if (root == nullptr)
return root;

// Standard BST delete if (key < root->key)
root->left = deleteNode(root->left, key); else if (key > root->key)
root->right = deleteNode(root->right, key); else {
// Node with only one child or no child
if (root->left == nullptr || root->right == nullptr) { Node* temp = root->left ? root->left : root->right;

// No child case
if (temp == nullptr) { temp = root;
root = nullptr;
} else // One child case
*root = *temp; // Copy the contents of the non-empty child delete temp;
} else {
// Node with two children, get the inorder successor (smallest in the right subtree) Node* temp = minValueNode(root->right);

// Copy the inorder successor's data to this node root->key = temp->key;

// Delete the inorder successor
root->right = deleteNode(root->right, temp->key);
}
}

// If the tree had only one node, return if (root == nullptr)
return root;

// Update height of current node
root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

// Get the balance factor
int balance = getBalanceFactor(root);

// Left Left Case
if (balance > 1 && getBalanceFactor(root->left) >= 0) return rightRotate(root);

// Left Right Case
if (balance > 1 && getBalanceFactor(root->left) < 0) { root->left = leftRotate(root->left);
return rightRotate(root);
}

// Right Right Case
if (balance < -1 && getBalanceFactor(root->right) <= 0) return leftRotate(root);

// Right Left Case
if (balance < -1 && getBalanceFactor(root->right) > 0) { root->right = rightRotate(root->right);
return leftRotate(root);
}

return root;
}

// Function to calculate the height of a tree int treeHeight(Node* root) {
if (root == nullptr) return 0;
return root->height;
}

int main() {
Node* root = nullptr;

// Insertion
root = insertNode(root, 10); root = insertNode(root, 20); root = insertNode(root, 30);

// Deletion
root = deleteNode(root, 20);

// Display
std::cout << "Inorder Traversal: "; inorderTraversal(root);
std::cout << std::endl;

// Height
std::cout << "Tree Height: " << treeHeight(root) << std::endl;

return 0;
}
