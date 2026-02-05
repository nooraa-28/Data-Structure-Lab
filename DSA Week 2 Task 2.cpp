#include <iostream>
using namespace std;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 2, num2 = 5;

    cout<<"Before swapping: num1 = "<<num1<<" and num2 = "<<num2<<endl;
    swap(&num1, &num2);
    cout<<"After swapping: num1 = "<<num1<<" and num2 = "<<num2<<endl;

    return 0;
}
