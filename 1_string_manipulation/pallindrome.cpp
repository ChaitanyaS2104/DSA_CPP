/*
In this problem we have to check whether the given string is a palindrome or not. 
String has alphanumeric characters (a-z, A-Z, 0-9) and symbols
- Ignore the non alphnums (isalnum function)
- Compare the alnums if unequal then pallindrome 
*/

#include<iostream>
#include<string> // Library used 
#include<cctype> // Library used 
using namespace std;

bool isPalindrome(string str);

int main(){
    string str;
    cin>>str;
    
    // auto identifies the data type on its own and '&' changes the actual variable value instead of making a copy of that
    
    for(auto &x: str){
        x = toupper(x);
    }
    isPalindrome(str);
    return 0;
}

bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }