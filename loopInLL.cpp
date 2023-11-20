#include <iostream>

struct Node { int data; Node* next;
};

class LinkedList { private:
Node* head;

public:
LinkedList() : head(nullptr) {}

// Function to insert a node at the end void insertNode(int value) {
Node* newNode = new Node{value, nullptr}; if (!head) {
head = newNode;
} else {
Node* temp = head; while (temp->next) {
temp = temp->next;
}
temp->next = newNode;
}
}

// Function to create a loop in the linked list void createLoop() {
if (head) {
Node* temp = head; while (temp->next) {
temp = temp->next;
}
temp->next = head;
}
}

// Function to detect a loop in the linked list bool detectLoop() {
Node* slow = head; Node* fast = head;

while (fast && fast->next) { slow = slow->next;
fast = fast->next->next;

if (slow == fast) {
return true; // Loop detected
}
}

return false; // No loop
}
};

int main() { LinkedList list;

// Inserting nodes list.insertNode(1); list.insertNode(2); list.insertNode(3); list.insertNode(4);

// Creating a loop list.createLoop();

// Detecting a loop
bool hasLoop = list.detectLoop();
std::cout << "Loop Detected: " << (hasLoop ? "Yes" : "No") << std::endl;

return 0;
}
