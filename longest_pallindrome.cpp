#include<iostream>
#include<string>

using namespace std;

int longest_pallindrome(string str);

int main(){
    string str;
    getline(cin, str);
    int res = longest_pallindrome(str);
    cout<<res<<endl;
    return 0;
}

int longest_pallindrome(string str){
    int max_length = 1;
    int left;
    int right;
    for(int i=0; i<str.length()-1; i++){
        int left = i-1;
        int right = i+1;
        // Odd pallindrome
        while(left>=0 && right<str.length() && str[left] == str[right]){
            max_length = max(max_length, right-left+1);
            left--;
            right++;
        }
        left = i;
        right = i+1;
        // Even pallindrome
        while(left>=0 && right<str.length() && str[left] == str[right]){
            max_length = max(max_length, right-left+1);
            left--;
            right++;
        }
    }

    return max_length;
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
