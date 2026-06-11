#include<iostream>
#include<string>

using namespace std;

bool make_pallindrome(string str);
bool is_pallindrome(string str, int start, int end);

int main(){
    string str;
    getline(cin, str);
    bool res = make_pallindrome(str);
    cout<<res<<endl;
    return 0;
}

bool make_pallindrome(string str){
    int left = 0;
    int right = str.length()-1;
    while(left < right){
        if(str[left] == str[right]){
            left++;
            right--;
        }
        else{
            return (is_pallindrome(str, left, right-1) || is_pallindrome(str, left+1, right));
        }
    }
    return true;
}

bool is_pallindrome(string str, int start, int end){
    int left = start;
    int right = end;
    while(left < right){
        if(str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}



/*
racecaar 
l      r
char_rem = false

racecaar
 l    r

racecaar
  l r
char_rem = true

*/