#include<iostream>
using namespace std;

void check_num(int num);

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    check_num(num);
    return 0;
}

void check_num(int num){
    if(num % 2 == 0) cout<<"Even\n";
    else cout<<"Odd\n";
}