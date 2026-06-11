#include<iostream>
#include<string>

using namespace std;

int ext_sum(string str);

int main(){
    string str;
    getline(cin, str);
    int sum = ext_sum(str);
    cout<<sum;
    return 0;
}

int ext_sum(string str){
    int sum = 0;
    int curr = 0;
    for(int i=0;i<str.length(); i++){
        if(isdigit(str[i])){
            curr = 10*curr + (str[i] - '0'); // -'0' to get the digit value
        }
        else{
            sum += curr;
            curr = 0;
        }
    }
    sum += curr;
    return sum;
}

/*
ab2d4c7 - sum=0, curr=0
          sum=0, curr=0
          sum=0, curr=0
          sum=0, curr=2
          sum=2, curr=0
          sum=2, curr=4
          sum=6, curr=0
          sum=6, curr=7
sum=13

*/