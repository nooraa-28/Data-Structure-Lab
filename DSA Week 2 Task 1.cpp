#include<iostream>
using namespace std;

int main() {
	 int arr[5] = {1, 2, 3, 4, 5};
	 int *ptr = arr;
	 
	 cout<<"Arrays Elements are: ";
	 for(int i=0; i<5; i++) {
	 	cout<< *ptr <<" ";
	 	ptr++;
	 }
	cout<<endl;
	return 0;
}
