#include <iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

// create list from user input (insert at end)
void insertEnd(int value){

    node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// add at beginning
void add(int value){

    node* newNode = new node();
    newNode->data = value;

    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;

    cout << value << " inserted at beginning.\n";
}

// insert after 45
void addAfter45(int value){

    node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL){
        cout << "45 not found.\n";
        return;
    }

    node* newNode = new node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    cout << value << " inserted after 45.\n";
}

// delete from beginning
void deleteBeginning(){

    if(head == NULL){
        cout << "List empty\n";
        return;
    }

    node* temp = head;

    cout << temp->data << " deleted from beginning.\n";

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// delete after 45
void deleteAfter45(){

    node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL){
        cout << "No node after 45.\n";
        return;
    }

    node* del = temp->next;

    cout << del->data << " deleted after 45.\n";

    temp->next = del->next;

    if(del->next != NULL)
        del->next->prev = temp;

    delete del;
}

// display list
void display(){

    node* temp = head;

    cout << "List: ";

    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main(){

    int n,value;

    cout << "Enter number of marks: ";
    cin >> n;

    for(int i=0;i<n;i++){
        cout << "Enter mark: ";
        cin >> value;
        insertEnd(value);
    }

    display();

    cout << "\nEnter value to insert at beginning: ";
    cin >> value;
    add(value);
    display();

    cout << "\nEnter value to insert after 45: ";
    cin >> value;
    addAfter45(value);
    display();

    deleteBeginning();
    display();

    deleteAfter45();
    display();
}