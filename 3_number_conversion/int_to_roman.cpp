#include <iostream>
#include<string>

using namespace std;

/*
- Convert an integer to a Roman numeral string.
- Uses a greedy mapping of values to symbols.
- Reads one integer from stdin and prints the Roman.
*/

string intToRoman(int num) {
    string res;
    int val[] = {1000, 900, 500, 400, 100, 90, 50,
                 40,   10,  9,   5,   4,   1};
    string l[]= {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                 "XL", "X",  "IX", "V",  "IV", "I"};
    for (int i = 0; i < 13; i++) {
        while (num >= val[i]) {
            num -= val[i];
            res += l[i];
        }
    }
    return res;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cout << intToRoman(n) << '\n';
    return 0;
}
