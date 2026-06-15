#include<iostream>
#include<vector>

using namespace std;

int max_subarray_sum(vector<int> &arr, int size, int k);

int main(){
    int size, k;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Value of k: ";
    cin>>k;

    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int result = max_subarray_sum(arr, size, k);
    cout<<result;
    return 0;
}

int max_subarray_sum(vector<int> &arr, int size, int k){
    int sum = 0;
    
    for(int i=0;i<k;i++){
        sum = sum + arr[i];
    }
    int max_sum = sum;
    
    for(int i=k; i<size; i++){
        sum = sum + arr[i] - arr[i-k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

/*
Size = 7

4  2  7  1  8  3  9     start = 0, end = 3, sum = 0, max_sum = 0
|-----|
  13
i = 0, 1
sum = 4, 6, 13 > max_sum
max_sum = 13
start = 1
end = 4  
sum = 0 

4  2  7  1  8  3  9
   |-----|
      10

4  2  7  1  8  3  9
      |-----|
        16

4  2  7  1  8  3  9
         |-----|
            11

4  2  7  1  8  3  9
            |-----|
              20


*/
