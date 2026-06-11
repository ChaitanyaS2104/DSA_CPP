#include<iostream>
#include<string> // Library used 
#include<cctype> // Library used 
using namespace std;

void pallindrome_checker(string str);

int main(){
    string str;
    cin>>str;
    
    // auto identifies the data type on its own and '&' changes the actual variable value instead of making a copy of that
    
    for(auto &x: str){
        x = toupper(x);
    }
    pallindrome_checker(str);
    return 0;
}

void pallindrome_checker(string str){
    for(int i=0; i< str.length()/2; i++){
        if(str[i] != str[str.length() - 1 - i]){
            cout<<"Not a pallindrome"<<endl;
            return;
        }
    }
    cout<<"Pallindrome"<<endl;
}