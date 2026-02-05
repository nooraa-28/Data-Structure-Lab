#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key;
    bool found = false;

    cout << "Enter element to search : ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index : " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found" << endl;
    }
    return 0;
}
