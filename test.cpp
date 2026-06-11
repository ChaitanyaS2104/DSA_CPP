#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    vector<int> arr(size);

    cout<<"Enter the array: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        if(arr[i] == i){
            cout<<i<<endl;
            return 0;
        };
    }
    cout<<"-1"<<endl;
    return -1;
}