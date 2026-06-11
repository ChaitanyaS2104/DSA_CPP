/*
We are given an array of elements 0,1 & 2, our goal is to sort the array such that the order is all 0's, all 1's and then all 2's. 
We cannot make a copy and are not allowed to use the inbuilt sorting functions

2 - High, 1 - Mid, 0 - Low

This problem is known as the Dutch National Flag problem where we have to sort three colors
- Set low,mid pointers to 0 (First element)
- Set high pointer to size-1 (Last element)
- We read the value at mid pointer
    - If it is 2 -> Swap it with value at High pointer and decrement High (-1) 
    (We dont increment Mid here bcz the value replaced is unknown (0 or 1) which needs to be processed)
    
    - Else if it is 1 -> Move to the Mid to next (Mid++)
    
    - Else (It will be a low value) -> Replace it with the value at Low pointer and increment Low & Mid (Since the replaced value will always be 1 so no need to check it) 

Use if, else if and else since only one condition can be true at a time

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

void category_sort(vector<int> &arr, int size);

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    category_sort(arr, size);
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    return 0;
}

void category_sort(vector<int> &arr, int size){
    int* low, *mid, *high;
    low = &arr[0];
    mid = &arr[0];
    high = &arr[size-1];

    while(mid <= high){
        int temp;
        if(*mid == 2){
            temp = *high;
            *high = *mid;
            *mid = temp;
            high--;
        }
        else if(*mid == 1) mid++;
        else{
            temp = *low;
            *low = *mid;
            *mid = temp;
            low++;
            mid++;
        }
    }
}

/*
2   0   2   1   1   0
l,m                 h
m = 2, swap with high

0   0   2   1   1   2
l   m           h
m = 0, swap with low

0   0   2   1   1   2
    l   m       h
m = 2, swap with high

0   0   1   1   2   2
    l       m,h

Example 2 - [ 0 0 ]

0   1
l,m h

0   1
    l,m,h
*/
