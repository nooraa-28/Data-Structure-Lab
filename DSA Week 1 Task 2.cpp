#include <iostream>
using namespace std;

int main() {
	int arr[3] = {10, 20, 30};
 	int index = 1;
 	int newValue = 50;
 	
 	arr[index] = newValue;
 	
 	cout<<"Updated Array: "<<endl;
 	for(int i = 0; i < 3; i++) {
 	cout << arr[i] << " ";
 	}
 	
 	return 0;
}
