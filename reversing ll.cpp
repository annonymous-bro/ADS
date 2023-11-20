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

// Function to display the linked list void displayList() {
Node* temp = head; while (temp) {
std::cout << temp->data << " "; temp = temp->next;
}
std::cout << std::endl;
}

// Function to reverse the linked list void reverseList() {
Node* prev = nullptr; Node* current = head; Node* next = nullptr;

while (current) {
next = current->next; current->next = prev; prev = current; current = next;
}

head = prev;
}
};

int main() { LinkedList list;

// Inserting nodes list.insertNode(1); list.insertNode(2); list.insertNode(3);

// Displaying the original linked list std::cout << "Original Linked List: "; list.displayList();

// Reversing the linked list list.reverseList();

// Displaying the reversed linked list std::cout << "Reversed Linked List: "; list.displayList();

return 0;
}
