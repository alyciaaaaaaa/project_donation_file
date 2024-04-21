#include <iostream>
#include <fstream>
#include "donor.h"

using namespace std;

int main() {
    LinkedList donorsList;

    char choice;
    do {
        string name;
        double amount;
        cout << "Enter donor's name: ";
        cin >> name;
        cout << "Enter donation amount: ";
        cin >> amount;
        donorsList.addDonor(name, amount);
        cout << "Do you want to add another donor? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    ofstream outFile("donors.txt");
    if (outFile.is_open()) {
        Donor* current = donorsList.getHead();
        while (current) {
            outFile << current->name << " " << current->amount << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Data has been saved to donors.txt" << endl;
    } else {
        cerr << "Unable to open file for writing!" << endl;
        return 1;
    }

    ifstream inFile("donors.txt");
    if (inFile.is_open()) {
        cout << "\nTop 5 donors:\n";
        string name;
        double amount;
        for (int i = 0; i < 5 && inFile >> name >> amount; ++i) {
            cout << "Name: " << name << ", Amount: " << amount << endl;
        }
        inFile.close();
    } else {
        cerr << "Unable to open file for reading!" << endl;
        return 1;
    }

    return 0;
}
