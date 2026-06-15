#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

void bubble_sort(vector<int> &arr, int size);

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    if(size<=0) return 0;
    
    vector<int> arr(size);

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    bubble_sort(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void bubble_sort(vector<int> &arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;
}

/*
5 6 3 4 2 1
i=0, j=0
5 < 6
5 6 3 4 2 1
i=0, j=1
6 > 3 - swap
5 3 6 4 2 1
i=0, j=2
6 > 4 - swap
5 3 4 6 2 1 
i=0, j=3
6 > 2 - swap
5 3 4 2 6 1
i=0, j=4
6 > 1 - swap
5 3 4 2 1 6
i=0, j=5 - stop 


*/
