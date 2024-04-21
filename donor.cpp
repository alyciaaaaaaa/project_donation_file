#include "donor.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        Donor* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addDonor(const string& name, double amount) {
    Donor* newDonor = new Donor{name, amount, nullptr};
    if (!head) {
        head = newDonor;
    } else {
        Donor* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newDonor;
    }
}

void LinkedList::displayTopDonors(int num) {
    Donor* current = head;
    cout << "\nTop " << num << " donors:\n"; // เปลี่ยน std::cout เป็น cout
    int count = 0;
    while (current && count < num) {
        cout << "Name: " << current->name << ", Amount: " << current->amount << endl; // เปลี่ยน std::cout เป็น cout
        current = current->next;
        count++;
    }
}

Donor* LinkedList::getHead() const {
    return head;
}
