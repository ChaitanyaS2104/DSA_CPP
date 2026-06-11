#include <iostream>
#include <string>
#include <map>

using namespace std;

int first_non_repeating(string str);

int main()
{
    string str;
    getline(cin, str);
    int res = first_non_repeating(str);
    cout << res << endl;
    return 0;
}

int first_non_repeating(string str)
{
    char non_r;
    map<char, int> dict;
    for (int i = 0; i < str.length(); i++)
    {
        dict[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (dict[str[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

/*
anagram
{
a-3
n-1
g-4
r-1
m-1
}

*/