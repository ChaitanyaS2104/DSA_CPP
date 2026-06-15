#include<iostream>
using namespace std;

void check_prime(int num);

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    check_prime(num);
    return 0;
}

void check_prime(int num){
    if(num == 1){
        cout<<"Composite\n";
        return;
    }
    if(num == 2){
        cout<<"Prime\n";
        return;
    }
    for(int i=2; i<num; i++){
        if(num % i == 0){
            cout<<"Not prime\n";
            return;
        }
    }
    cout<<"Prime\n";
}