#include <iostream>

using namespace std;

string convertToBase7(int num);

int main()
{
    int n;
    cin >> n;
    string res = convertToBase7(n);
    cout << res<<endl;
    return 0;
}

string convertToBase7(int num)
{
    string base;
    if (num == 0)
        return "0";
    bool neg = false;
    if (num < 0)
    {
        neg = true;
        num *= -1;
    }
    while (num > 0)
    {
        char digit = (num % 7) + '0';
        base = digit + base;
        num /= 7;
    }
    return neg == true ? "-" + base : base;
}