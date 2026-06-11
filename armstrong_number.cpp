// Armstrong number is a number in which the sum of the individual digits raise to the power of the total number of digits is same as the number itself
// ex. 153 = 1^3 + 5^3 + 3^3

#include<iostream>
#include<cmath> // Library used 

using namespace std;

void check_armstrong(int num);

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    check_armstrong(num);
    return 0;
}

void check_armstrong(int num){
    int num_copy = num;
    int digit = 1;
    while(true){
        if(num_copy % 10 == num_copy){
            break;
        }
        digit++;
        num_copy = num_copy / 10;
    }

    int sum = 0;
    num_copy = num;

    while (true)
    {
        int curr_dig = num_copy % 10; //remainder
        cout<<curr_dig<<endl;
        sum += pow(curr_dig, digit);
        num_copy = num_copy / 10; //quotient
        if(num_copy == 0) break;
    }
    if(sum == num){
        cout<<"Armstrong Number"<<endl;
        return;
    }
    cout<<"Not an armstrong number"<<endl;
}


/*
digit = 1 

153 % 10 = 15 , 3 (digit = 2)
15 % 10 = 1, 5 (digit = 3)
1 % 10 = 0, 1 Stop

sum = 0 
153 % 10 = 15, 3 (sum = 0 + 3^3)
15 % 10 = 1, 5 (sum = 9 + 5^3)
1 % 10 = 0, 1
0 
*/