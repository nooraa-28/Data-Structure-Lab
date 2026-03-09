#include <iostream>
using namespace std;

struct node{
    string name;
    int score;
    node* prev;
    node* next;
};

node* head = NULL;

// add player in sorted order
void addPlayer(string name,int score){

    node* newNode = new node();
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
        cout<<"Player added.\n";
        return;
    }

    node* temp = head;

    while(temp != NULL && temp->score < score)
        temp = temp->next;

    // insert at beginning
    if(temp == head){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // insert at end
    else if(temp == NULL){
        node* last = head;

        while(last->next != NULL)
            last = last->next;

        last->next = newNode;
        newNode->prev = last;
    }

    // insert in middle
    else{
        newNode->prev = temp->prev;
        newNode->next = temp;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    cout<<"Player added in sorted order.\n";
}

// delete player by name
void deletePlayer(string name){

    node* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL){
        cout<<"Player not found.\n";
        return;
    }

    if(temp == head)
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    cout<<temp->name<<" deleted.\n";

    delete temp;
}

// display whole list
void display(){

    if(head == NULL){
        cout<<"List empty.\n";
        return;
    }

    node* temp = head;

    cout<<"\nPlayers List:\n";

    while(temp != NULL){
        cout<<temp->name<<"  Score: "<<temp->score<<endl;
        temp = temp->next;
    }
}

// lowest score player
void lowestScore(){

    if(head == NULL){
        cout<<"List empty.\n";
        return;
    }

    cout<<"Lowest Score Player: "
        <<head->name<<" ("<<head->score<<")\n";
}

// players with same score
void sameScore(int score){

    node* temp = head;
    bool found = false;

    while(temp != NULL){

        if(temp->score == score){
            cout<<temp->name<<"  "<<temp->score<<endl;
            found = true;
        }

        temp = temp->next;
    }

    if(!found)
        cout<<"No player with this score.\n";
}

// backward from player
void backwardFrom(string name){

    node* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL){
        cout<<"Player not found.\n";
        return;
    }

    if(temp->prev == NULL){
        cout<<"No player behind "<<name<<".\n";
        return;
    }

    cout<<"Players behind "<<name<<":\n";

    temp = temp->prev;

    while(temp != NULL){
        cout<<temp->name<<"  "<<temp->score<<endl;
        temp = temp->prev;
    }
}

int main(){

    int choice,score;
    string name;

    while(true){

        cout<<"\n--- Golf Tournament Menu ---\n";
        cout<<"1. Add Player\n";
        cout<<"2. Delete Player\n";
        cout<<"3. Display Players\n";
        cout<<"4. Lowest Score Player\n";
        cout<<"5. Players with Same Score\n";
        cout<<"6. Backward From Player\n";
        cout<<"7. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            cout<<"Enter player name: ";
            cin>>name;
            cout<<"Enter score: ";
            cin>>score;
            addPlayer(name,score);
            break;

        case 2:
            cout<<"Enter player name to delete: ";
            cin>>name;
            deletePlayer(name);
            break;

        case 3:
            display();
            break;

        case 4:
            lowestScore();
            break;

        case 5:
            cout<<"Enter score: ";
            cin>>score;
            sameScore(score);
            break;

        case 6:
            cout<<"Enter player name: ";
            cin>>name;
            backwardFrom(name);
            break;

        case 7:
            return 0;

        default:
            cout<<"Invalid choice\n";
        }
    }
}