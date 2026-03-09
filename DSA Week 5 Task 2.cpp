#include <iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

// insert at end
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

// display rainfall list
void display(){

    node* temp = head;
    int day = 1;

    cout << "\nRainfall List:\n";

    while(temp != NULL){
        cout << "Day " << day << " : " << temp->data << endl;
        temp = temp->next;
        day++;
    }
}

// calculate statistics
void rainfallStats(){

    node* temp = head;

    int total = 0;
    int count = 0;
    int max = -1, min = 9999;
    int maxDay = 0, minDay = 0;
    int day = 1;

    while(temp != NULL){

        total += temp->data;

        if(temp->data > max){
            max = temp->data;
            maxDay = day;
        }

        if(temp->data < min){
            min = temp->data;
            minDay = day;
        }

        temp = temp->next;
        day++;
        count++;
    }

    cout << "\nTotal Rainfall = " << total << endl;
    cout << "Average Rainfall = " << (float)total/count << endl;
    cout << "Highest Rainfall on Day " << maxDay << endl;
    cout << "Lowest Rainfall on Day " << minDay << endl;
}

// rainfall after 5th node
void after5th(){

    node* temp = head;
    int count = 1;

    while(temp != NULL && count < 6){
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
        cout << "Rainfall after 5th node = " << temp->data << endl;
    else
        cout << "No node after 5th day\n";
}

int main(){

    int rain;

    for(int i = 1; i <= 7; i++){

        cout << "Enter rainfall for Day " << i << " : ";
        cin >> rain;

        if(rain < 0){
            cout << "Negative rainfall not allowed. Enter again.\n";
            i--;
            continue;
        }

        insertEnd(rain);
    }

    display();
    rainfallStats();
    after5th();
}