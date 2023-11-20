#include <iostream>

struct Node { int data; Node* next;
};

class CircularLinkedList { private:
Node* head;

public:
CircularLinkedList() : head(nullptr) {}

// Function to insert a node at the end void insertNode(int value) {
Node* newNode = new Node{value, nullptr}; if (!head) {
head = newNode; newNode->next = head;
} else {
Node* temp = head;
while (temp->next != head) { temp = temp->next;
}
temp->next = newNode; newNode->next = head;
}
}

// Function to display the linked list void displayList() {
if (!head) { return;
}
Node* temp = head; do {
std::cout << temp->data << " "; temp = temp->next;
} while (temp != head); std::cout << std::endl;
}
};

int main() { CircularLinkedList list;

// Inserting nodes list.insertNode(1); list.insertNode(2); list.insertNode(3);

// Displaying the linked list std::cout << "Linked List: "; list.displayList();

return 0;
}
