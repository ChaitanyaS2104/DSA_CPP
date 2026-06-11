/*
We have to push all the zeros present in the array to the right most end by maintaining the relative order of the non zero numbers
- Use read and write pointers
- When value at read pointer is non zero swap it with the write pointer, increment the write pointer
- When value at read pointer is zero continue
- This ensures that the write pointer is pointing at the end of the non zero numbers
- Time complexity of this is O(n)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

void push_zero(vector<int> &arr, int size);

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    if(size<=0) return 1;
    vector<int> arr(size);

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    push_zero(arr, size);
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void push_zero(vector<int> &arr, int size){
    int* write = &arr[0];
    for(int read=0; read<size; read++){
        if(arr[read] != 0){
            int temp = *write;
            *write = arr[read];
            arr[read] = temp;
            write++;
        }
    }
}

/*

2   0   3   0   1   0
w/r
r != 0 , swap

2   0   3   0   1   0
    w/r
r == 0, 

2   0   3   0   1   0
    w   r
r != 0, swap

2   3   0   0   1   0
        w   r
r == 0

2   3   0   0   1   0
        w       r
r != 0, swap 

2   3   1   0   0   0
            w       r
r == size, stop 

*/