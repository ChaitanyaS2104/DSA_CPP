/*
We need to find the largest pallindrome in the string and return it with its length

Brute Force
- Expand around every index (for odd and even pal) and update the largest pallindrome accordingly

Optimal Solution

*/
 
#include <iostream>
#include <string>

using namespace std;

int longest_pallindrome_length(string str);
string longestPalindrome(string s);

int main()
{
    string str;
    getline(cin, str);
    int res = longest_pallindrome_length(str);
    string res_s = longestPalindrome(str);
    cout <<res_s<<" Length: "<< res << endl;
    return 0;
}

int longest_pallindrome_length(string str)
{
    int max_length = 1;
    int left;
    int right;
    for (int i = 0; i < str.length() - 1; i++)
    {
        int left = i - 1;
        int right = i + 1;
        // Odd pallindrome
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            max_length = max(max_length, right - left + 1);
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        // Even pallindrome
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            max_length = max(max_length, right - left + 1);
            left--;
            right++;
        }
    }

    return max_length;
}

string longestPalindrome(string s)
{
    int w_len = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int l = i;
        int r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        if (r - l - 1 > w_len)
        {
            start = l + 1;
            w_len = r - l - 1;
        }

        l = i;
        r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        if (r - l - 1 > w_len)
        {
            start = l + 1;
            w_len = r - l - 1;
        }
    }
    return s.substr(start, w_len);
}

/*
size = 8
granddad - max = 1, l=0, r=2, i=1, len=1
 |
0 >= 0 and 2 < 8 and g != a -> len 1, stop

granddad - max = 1, l=1, r=3, i=2, len=1
  |
1 >= 0 and 3 < 8 and r != n

granddad
   |

granddad
    |

granddad
     |

granddad
      |

abba

*/
