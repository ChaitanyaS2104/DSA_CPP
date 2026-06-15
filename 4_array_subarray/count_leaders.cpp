#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int count_leaders(vector<int> &arr, int size);

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int result = count_leaders(arr, size);
    cout<<result<<endl;
    return 0;
}

int count_leaders_brute(vector<int> &arr, int size){
    int count=0;
    for(int i=0;i<size;i++){
        bool max_num = true;
        for(int j=i+1;j<size;j++){
            if(arr[i] < arr[j]){
                max_num = false;
                break;
            }
        }
        if(max_num) count++;
    }
    return count;
}

int count_leaders(vector<int> &arr, int size){
    int count=0;
    int max = arr[size-1]; // start from right most element
    for(int i=size-1;i>=0;i--){
        if(arr[i] >= max){
            max=arr[i];
            count++;
        } 
    }
    return count;
}