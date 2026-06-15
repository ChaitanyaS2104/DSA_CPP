/*
We need to find whether the two given strings are anagrams or not 
- We use an array instead of map since its computationally easy than using hash map
- Store the frequency of each char for first string 
- Reduce the frequency of each char for second string
- Array should be zero if its an anagram
*/

#include <iostream>
#include <string>
#include<vector>
#include <cctype>

using namespace std;

bool is_anagram(string str1, string str2);

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);

    bool res = is_anagram(str1, str2);
    cout << res << endl;
    return 0;
}

bool is_anagram(string str1, string str2)
{
    vector<int>freq(26, 0);
    for(auto& x: str1){
        freq[tolower(x) - 'a']++;
    }
    for(auto& x: str2){
        freq[tolower(x) - 'a']--;
    }
    for(auto& x: freq){
        if(x != 0) return false; 
    }
    return true;
}