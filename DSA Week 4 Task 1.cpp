#include <iostream>
using namespace std;

// Node structure
struct Node {
    string brandName;
    int unitsInStock;
    float price;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Function to add a new mobile
void addMobile(string brand, int units, float price) {
    Node* newNode = new Node();

    newNode->brandName = brand;
    newNode->unitsInStock = units;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Mobile added successfully!\n";
}

// Function to delete a mobile by brand name
void deleteMobile(string brand) {
    if (head == NULL) {
        cout << "Inventory is empty!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->brandName == brand) {
        head = temp->next;
        delete temp;
        cout << "Mobile deleted successfully!\n";
        return;
    }

    // Search for the mobile
    while (temp != NULL && temp->brandName != brand) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Mobile not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Mobile deleted successfully!\n";
}

// Function to display all mobiles
void displayMobiles() {
    if (head == NULL) {
        cout << "Inventory is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "\nMobile Inventory:\n";
    cout << "--------------------------\n";

    while (temp != NULL) {
        cout << "Brand Name: " << temp->brandName << endl;
        cout << "Units in Stock: " << temp->unitsInStock << endl;
        cout << "Price: $" << temp->price << endl;
        cout << "--------------------------\n";
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice;
    string brand;
    int units;
    float price;

    do {
        cout << "\n===== Mobile Inventory Menu =====\n";
        cout << "1. Add Mobile\n";
        cout << "2. Delete Mobile\n";
        cout << "3. Display All Mobiles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Brand Name: ";
                cin >> brand;
                cout << "Enter Units in Stock: ";
                cin >> units;
                cout << "Enter Price: ";
                cin >> price;
                addMobile(brand, units, price);
                break;

            case 2:
                cout << "Enter Brand Name to delete: ";
                cin >> brand;
                deleteMobile(brand);
                break;

            case 3:
                displayMobiles();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}