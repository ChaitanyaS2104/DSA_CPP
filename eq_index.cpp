#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int eq_index(vector<int> &arr, int size);

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int result = eq_index(arr, size);
    cout<<result<<endl;
    return 0;
}

int eq_index(vector<int> &arr, int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += arr[i];
    }

    int acc =0;
    for(int i=0;i<size;i++){
        int sum_right = sum-acc-arr[i];
        if(sum_right == acc) return i;
        acc += arr[i]; 
    }
    return -1;
}