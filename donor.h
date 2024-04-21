#ifndef DONOR_H
#define DONOR_H

#include <string>
#include <iostream> 

using namespace std;

struct Donor {
    string name;
    double amount;
    Donor* next;
};

class LinkedList {
private:
    Donor* head;

public:
    LinkedList();
    ~LinkedList();
    void addDonor(const string& name, double amount);
    void displayTopDonors(int num);
    Donor* getHead() const;
};

#endif
