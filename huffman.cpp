#include <iostream> #include <queue>
#include <unordered_map> #include <string>

using namespace std;

// Huffman Tree Node struct HuffmanNode {
char data; int freq;
HuffmanNode *left, *right;

HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for the priority queue struct CompareNodes {
bool operator()(HuffmanNode* a, HuffmanNode* b) { return a->freq > b->freq;
}
};

// Function to build Huffman Tree and return the root
HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes>& minHeap) {
while (minHeap.size() > 1) { HuffmanNode* left = minHeap.top(); minHeap.pop();
HuffmanNode* right = minHeap.top(); minHeap.pop();

HuffmanNode* internalNode = new HuffmanNode('$', left->freq + right->freq); internalNode->left = left;
internalNode->right = right;

minHeap.push(internalNode);
}

return minHeap.top();
}

// Function to traverse the Huffman Tree and generate codes
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
if (root) {
if (root->data != '$') { huffmanCodes[root->data] = code;
}

generateHuffmanCodes(root->left, code + "0", huffmanCodes); generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}
}

// Function to encode the input using Huffman codes
string huffmanEncode(string input, unordered_map<char, string>& huffmanCodes) { string encodedString = "";
for (char c : input) {
encodedString += huffmanCodes[c];
}
return encodedString;
}

// Main function for Huffman Encoding int main() {
string input = "abracadabra"; unordered_map<char, int> frequencyMap;

// Calculate frequencies for (char c : input) {
frequencyMap[c]++;
}

// Create a priority queue for Huffman Nodes
priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

// Populate priority queue with initial nodes for (auto& entry : frequencyMap) {
minHeap.push(new HuffmanNode(entry.first, entry.second));
}

// Build Huffman Tree
HuffmanNode* root = buildHuffmanTree(minHeap);
 
// Generate Huffman Codes unordered_map<char, string> huffmanCodes; generateHuffmanCodes(root, "", huffmanCodes);

// Encode the input
string encodedString = huffmanEncode(input, huffmanCodes);

// Display results
cout << "Original String: " << input << endl;
cout << "Encoded String: " << encodedString << endl;

return 0;
}
