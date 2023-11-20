#include <iostream>

struct Node { int data; Node* next; Node* prev;
};

class DoublyLinkedList { private:
Node* head;

public:
DoublyLinkedList() : head(nullptr) {}

// Function to insert a node at the end void insertNode(int value) {
Node* newNode = new Node{value, nullptr, nullptr}; if (!head) {
head = newNode;
} else {
Node* temp = head; while (temp->next) {
temp = temp->next;
}
temp->next = newNode; newNode->prev = temp;
}
}

// Function to display the linked list void displayList() {
Node* temp = head; while (temp) {
std::cout << temp->data << " "; temp = temp->next;
}
std::cout << std::endl;
}
};

int main() {
DoublyLinkedList list;

// Inserting nodes list.insertNode(1); list.insertNode(2); list.insertNode(3);

// Displaying the linked list std::cout << "Linked List: "; list.displayList();

return 0;
}
