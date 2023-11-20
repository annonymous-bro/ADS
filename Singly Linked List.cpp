#include <iostream>

struct Node { int data; Node* next;
};

class SinglyLinkedList { private:
Node* head;

public:
SinglyLinkedList() : head(nullptr) {}

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
};
int main() { SinglyLinkedList list;

// Inserting nodes list.insertNode(1); list.insertNode(2); list.insertNode(3);

// Displaying the linked list std::cout << "Linked List: "; list.displayList();

return 0;
}
