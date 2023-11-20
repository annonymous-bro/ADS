#include <iostream>

struct Term {
int coefficient; int exponent; Term* next;
};

class Polynomial { private:
Term* head;

public:
Polynomial() : head(nullptr) {}

// Function to insert a term into the polynomial void insertTerm(int coefficient, int exponent) {
Term* newTerm = new Term{coefficient, exponent, nullptr}; if (!head || exponent > head->exponent) {
newTerm->next = head; head = newTerm;
} else {
Term* temp = head;
while (temp->next && temp->next->exponent > exponent) { temp = temp->next;
}
newTerm->next = temp->next; temp->next = newTerm;
}
}

// Function to display the polynomial void displayPolynomial() {
Term* temp = head; while (temp) {
std::cout << temp->coefficient << "x^" << temp->exponent; if (temp->next) {
std::cout << " + ";
}
temp = temp->next;
}
std::cout << std::endl;
}
};

int main() { Polynomial poly;

// Inserting terms into the polynomial poly.insertTerm(3, 2);
poly.insertTerm(5, 1);
poly.insertTerm(2, 0);

// Displaying the polynomial std::cout << "Polynomial: "; poly.displayPolynomial();

return 0;
}
