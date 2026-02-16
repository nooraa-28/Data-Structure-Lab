#include <iostream>
using namespace std;

int main() {
    char *ch = new char;

    cout<<"Enter a character: ";
    cin>>ch;           

    cout<<"Stored character: "<<ch<<endl;

    delete ch;
	ch = nullptr;
    return 0;
}
