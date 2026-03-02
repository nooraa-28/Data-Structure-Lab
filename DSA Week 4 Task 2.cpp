#include <iostream>
using namespace std;

// Node structure for User Profile
struct Node {
    string username;
    string fullName;
    int age;
    string bio;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Create Profile
void createProfile(string uname, string fname, int age, string bio) {
    Node* newNode = new Node();
    newNode->username = uname;
    newNode->fullName = fname;
    newNode->age = age;
    newNode->bio = bio;
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

    cout << "Profile created successfully!\n";
}

// Search Profile
Node* searchProfile(string uname) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->username == uname) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Update Profile
void updateProfile(string uname) {
    Node* user = searchProfile(uname);

    if (user == NULL) {
        cout << "Profile not found!\n";
        return;
    }

    cout << "Enter new Full Name: ";
    cin >> user->fullName;
    cout << "Enter new Age: ";
    cin >> user->age;
    cout << "Enter new Bio: ";
    cin >> user->bio;

    cout << "Profile updated successfully!\n";
}

// Delete Profile
void deleteProfile(string uname) {
    if (head == NULL) {
        cout << "No profiles available!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->username == uname) {
        head = temp->next;
        delete temp;
        cout << "Profile deleted successfully!\n";
        return;
    }

    while (temp != NULL && temp->username != uname) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Profile not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Profile deleted successfully!\n";
}

// View All Profiles
void viewAllProfiles() {
    if (head == NULL) {
        cout << "No profiles available!\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== All User Profiles =====\n";
    while (temp != NULL) {
        cout << "Username: " << temp->username << endl;
        cout << "Full Name: " << temp->fullName << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Bio: " << temp->bio << endl;
        cout << "---------------------------\n";
        temp = temp->next;
    }
}

// Main Function
int main() {
    int choice;
    string username, fullName, bio;
    int age;

    do {
        cout << "\n===== Social Media Portal =====\n";
        cout << "1. Create Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. View All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Full Name: ";
            cin >> fullName;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Bio: ";
            cin >> bio;
            createProfile(username, fullName, age, bio);
            break;

        case 2:
            cout << "Enter Username to Update: ";
            cin >> username;
            updateProfile(username);
            break;

        case 3:
            cout << "Enter Username to Delete: ";
            cin >> username;
            deleteProfile(username);
            break;

        case 4:
        {
            cout << "Enter Username to Search: ";
            cin >> username;
            Node* user = searchProfile(username);
            if (user != NULL) {
                cout << "Profile Found!\n";
                cout << "Username: " << user->username << endl;
                cout << "Full Name: " << user->fullName << endl;
                cout << "Age: " << user->age << endl;
                cout << "Bio: " << user->bio << endl;
            } else {
                cout << "Profile not found!\n";
            }
            break;
        }

        case 5:
            viewAllProfiles();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}