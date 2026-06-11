#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string rev_words_sen(string &str);


int main()
{
    string str;
    getline(cin, str);
    string rev = rev_words_sen(str);
    cout << rev;
    return 0;
}

string rev_words_sen(string &str)
{
    // __i_am_the_blue_____
    int end = 0;
    
    reverse(str.begin(), str.end());
    
    string rev = "";
    string word = "";

    // _____eulb_eht_ma_i__
    while(end < str.length()){
        while(end < str.length() && str[end] != ' '){
            word += str[end];
            end++;
        }
        
        if(word.length() > 0) {
            reverse(word.begin(), word.end());
            rev = rev + " " + word;
            word = "";
        }
        end++;
    }
    return rev.substr(1);
}
