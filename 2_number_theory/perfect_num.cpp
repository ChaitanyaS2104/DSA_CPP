// Perfect number is a number whose sum of divisors (excluding the number itself) is equal to the number ex. 6 = 1 + 2 + 3 

#include<iostream>

using namespace std;

void perfect_num(int num);

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    perfect_num(num);
    return 0;
}

void perfect_num(int num){
    int sum = 0;
    for(int i=1; i <num; i++){
        if(num % i == 0){
            sum+= i;
        }
    }
    if(num == sum){
        cout<<"Perfect number"<<endl;
        return;
    }
    cout<<"Not a perfect number"<<endl;
}