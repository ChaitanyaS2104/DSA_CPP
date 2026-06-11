#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

bool is_anagram(string str1, string str2);

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    for(int i=0; i<str1.length();i++){
        str1[i] = toupper(str1[i]);
    }
    for(int i=0; i<str2.length();i++){
        str2[i] = toupper(str2[i]);
    }

    bool res = is_anagram(str1, str2);
    cout << res << endl;
    return 0;
}

bool is_anagram(string str1, string str2)
{
    map<char, int> word_map1;
    map<char, int> word_map2;

    if(str1.length() != str2.length()) return false;

    for (int i=0; i<str1.length();i++)
    {
        if (word_map1.find(str1[i]) != word_map1.end())
            word_map1[str1[i]]++;
        else
            word_map1[str1[i]] = 1;
    }
    for (int i=0; i<str2.length();i++)
    {
        if (word_map2.find(str2[i]) != word_map2.end())
            word_map2[str2[i]]++;
        else
            word_map2[str2[i]] = 1;
    }
    return (word_map1==word_map2);
}