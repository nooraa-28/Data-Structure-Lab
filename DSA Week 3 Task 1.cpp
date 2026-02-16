#include <iostream>
using namespace std;

struct Product{
	string name;
    int code;
    float price;
};

int main() {
    int n;

    cout<<"Enter number of products: ";
    cin>>n;

    Product* prod = new Product[n];

    for (int i = 0; i < n; i++) {
        cout<<"\nEnter details for product "<<i + 1<<endl;

        cout<<"Name: ";
        cin>>prod[i].name;

        cout<<"Code: ";
        cin>>prod[i].code;

        cout<<"Price: ";
        cin>>prod[i].price;
    }
	cout<<endl;
    cout<<"   Product List   "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"\nProduct "<<i + 1<<endl;
        cout<<"Name : "<<prod[i].name<<endl;
        cout<<"Code : "<<prod[i].code<<endl;
        cout<<"Price Rs: "<<prod[i].price<<endl;
    }

    delete[] prod;
    return 0;
}

