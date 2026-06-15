#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"a :";
    cin>>a;
    int b;
    cout<<"b :";
    cin>>b;

    int* pt_a = &a;
    int* pt_b = &b;

    int* temp = pt_a;
    pt_a = pt_b;
    pt_b = temp;

    cout<<"a = "<<*pt_a<<endl;
    cout<<"b = "<<*pt_b<<endl;

    return 0;
}