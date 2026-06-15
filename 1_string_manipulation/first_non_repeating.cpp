#include <iostream>
#include <string>
#include <map>

using namespace std;

int firstUniqChar(string str);

int main()
{
    string str;
    getline(cin, str);
    int res = firstUniqChar(str);
    cout << res << endl;
    return 0;
}

int firstUniqChar(string s)
{
    vector<int> freq(26, 0);
    for (auto &x : s)
    {
        freq[x - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (freq[s[i] - 'a'] == 1)
            return i;
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