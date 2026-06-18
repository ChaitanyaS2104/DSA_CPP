/*
- Converts a string representation of an integer into an integer value.
- Handles spaces, signs, and overflow safely.
*/

#include <cctype>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

int Atoi(string s);

int main()
{
    string str;
    getline(cin, str);
    int num = Atoi(str);
    cout << num << endl;
    return 0;
}

int Atoi(string s)
{
    int n = s.length();
    int p = 0;
    bool neg = false;
    long long num = 0;

    while (p < n && s[p] == ' ')
        p++;

    if (p < n && (s[p] == '-' || s[p] == '+'))
    {
        neg = (s[p] == '-');
        p++;
    }

    while (p < n && isdigit(s[p]))
    {
        int digit = s[p] - '0';

        if (!neg)
        {
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7))
                return INT_MAX;
        }
        else
        {
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 8))
                return INT_MIN;
        }

        num = num * 10 + digit;
        p++;
    }

    return neg ? -num : num;
}
