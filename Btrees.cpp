#include <iostream> #include <vector>

using namespace std;
const int M = 3; // B-Tree order, adjust as needed struct BTreeNode {
vector<int> keys; vector<BTreeNode*> children; bool isLeaf;

BTreeNode() { isLeaf = true;
}
};

void fill(BTreeNode* node, int index);
void borrowFromPrev(BTreeNode* node, int index); void borrowFromNext(BTreeNode* node, int index); void merge(BTreeNode* node, int index);

BTreeNode* createNode() {
BTreeNode* newNode = new BTreeNode(); newNode->children.resize(M + 1, nullptr); return newNode;
}

void splitChild(BTreeNode* parent, int index, BTreeNode* child) { BTreeNode* newNode = createNode();
newNode->isLeaf = child->isLeaf;
parent->keys.insert(parent->keys.begin() + index, child->keys[M / 2]); parent->children.insert(parent->children.begin() + index + 1, newNode);

newNode->keys.assign(child->keys.begin() + (M / 2) + 1, child->keys.end()); child->keys.resize(M / 2);

if (!child->isLeaf) {
newNode->children.assign(child->children.begin() + (M / 2) + 1, child->children.end()); child->children.resize(M / 2 + 1);
}
}

void insert(BTreeNode*& root, int key);

void insertNonFull(BTreeNode* node, int key) { int i = node->keys.size() - 1;

if (node->isLeaf) {
node->keys.push_back(0);
while (i >= 0 && key < node->keys[i]) { node->keys[i + 1] = node->keys[i];
i--;
}
node->keys[i + 1] = key;
} else {
while (i >= 0 && key < node->keys[i]) { i--;
}

i++;
if (node->children[i]->keys.size() == M - 1) { splitChild(node, i, node->children[i]);
if (key > node->keys[i]) { i++;
}
}
insertNonFull(node->children[i], key);
}
}

int getHeight(BTreeNode* root) { if (!root) {
return 0;
}
return getHeight(root->children[0]) + 1;
}

int getPredecessor(BTreeNode* node) { while (!node->isLeaf) {
node = node->children.back();
}
return node->keys.back();
}

void fill(BTreeNode* node, int index) { BTreeNode* child = node->children[index];
if (index > 0 && node->children[index - 1]->keys.size() >= (M + 1) / 2) { borrowFromPrev(node, index);
} else if (index < node->keys.size() && node->children[index + 1]->keys.size() >= (M + 1) / 2) { borrowFromNext(node, index);
} else {
if (index != node->keys.size()) { merge(node, index);
} else {
merge(node, index - 1);
}
}
}
void borrowFromPrev(BTreeNode* node, int index) { BTreeNode* child = node->children[index]; BTreeNode* sibling = node->children[index - 1];
child->keys.insert(child->keys.begin(), node->keys[index - 1]); if (!child->isLeaf) {
child->children.insert(child->children.begin(), sibling->children.back()); sibling->children.pop_back();
}

node->keys[index - 1] = sibling->keys.back(); sibling->keys.pop_back();
}

void borrowFromNext(BTreeNode* node, int index) { BTreeNode* child = node->children[index]; BTreeNode* sibling = node->children[index + 1];
child->keys.push_back(node->keys[index]); if (!child->isLeaf) {
child->children.push_back(sibling->children.front()); sibling->children.erase(sibling->children.begin());
}

node->keys[index] = sibling->keys.front(); sibling->keys.erase(sibling->keys.begin());
}

void merge(BTreeNode* node, int index) { BTreeNode* child = node->children[index]; BTreeNode* sibling = node->children[index + 1];

child->keys.push_back(node->keys[index]);
child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end()); if (!child->isLeaf) {
child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
}

node->keys.erase(node->keys.begin() + index);
node->children.erase(node->children.begin() + index + 1);

delete sibling;
}

void remove(BTreeNode*& root, int key) { if (!root) {
cout << "Key not found in the B-Tree.\n";
return;
}

int index = 0;
while (index < root->keys.size() && key > root->keys[index]) { index++;
}

if (index < root->keys.size() && key == root->keys[index]) { if (root->isLeaf) {
root->keys.erase(root->keys.begin() + index);
} else {
BTreeNode* predecessor = root->children[index]; int predKey = getPredecessor(predecessor);

root->keys[index] = predKey; remove(predecessor, predKey);
}
} else {
BTreeNode* child = root->children[index]; if (child->keys.size() < (M + 1) / 2) {
fill(root, index);
}
remove(child, key);
}
}

void inOrderTraversal(BTreeNode* root) { if (root) {
for (size_t i = 0; i < root->keys.size(); ++i) { if (!root->isLeaf) {
inOrderTraversal(root->children[i]);
}
cout << root->keys[i] << " ";
}
if (!root->isLeaf) {
inOrderTraversal(root->children.back());
}
}
}

void displayBTree(BTreeNode* root, int level = 0) { if (root) {
for (int i = root->keys.size() - 1; i >= 0; i--) { displayBTree(root->children[i + 1], level + 1); for (int j = 0; j < level; j++) {
cout << "	";
}
cout << root->keys[i] << "\n";
}
displayBTree(root->children[0], level + 1);
}
}

void insert(BTreeNode*& root, int key) { if (!root) {
root = createNode();
root->keys.push_back(key);
} else {
if (root->keys.size() == M - 1) { BTreeNode* newNode = createNode(); newNode->isLeaf = false;
newNode->children[0] = root; splitChild(newNode, 0, root); root = newNode;
}
insertNonFull(root, key);
}
}


int main() {
BTreeNode* root = nullptr;

// Inserting keys into the B-Tree insert(root, 10);
insert(root, 20);
insert(root, 5);
insert(root, 6);
insert(root, 12);
insert(root, 30);
insert(root, 7);

cout << "In-order Traversal of B-Tree: "; inOrderTraversal(root);
cout << "\n";

cout << "Displaying B-Tree:\n"; displayBTree(root);

// Finding the height of the B-Tree int height = getHeight(root);
cout << "Height of the B-Tree: " << height << "\n";

// Deleting a key from the B-Tree (e.g., deleting key 20) remove(root, 20);

cout << "In-order Traversal of B-Tree after deletion: "; inOrderTraversal(root);
cout << "\n";

cout << "Displaying B-Tree after deletion:\n";
displayBTree(root);

return 0;
}
