#include<iostream>
#include<vector>

using namespace std;

int container(vector<int> &arr, int size);

int main(){
    int size;
    cout<<"Size: ";
    cin>>size;

    vector<int> arr(size);

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int result = container(arr, size);
    cout<<result<<endl;
    return 0;
}

int container_brute(vector<int> &arr, int size){
    int vol = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            int area = (j - i) * min(arr[i], arr[j]);
            vol = max(vol, area);
        }
    }
    return vol;
}

int container(vector<int> &arr, int size){
    int vol = 0;
    int left =0;
    int right = size -1;
    while(left < right){
        int width = right - left;
        int height = min(arr[left], arr[right]);
        int cont_vol = width * height;
        vol = max(vol, cont_vol);
        arr[left] > arr[right] ? right-- : left++;
    }
    return vol;
}

/*

1 8 6 2 5 4 8 3 7.    vol = min(1,6) * (2 - 0) = 2
|---|
l   r

1 8 6 2 5 4 8 3 7.    vol = min(1,6) * (2 - 0) = 2
|---|


1 8 6 2 5 4 8 3 7.    vol = min(8,7) * (8 - 1) = 49
|-----|
        49

*/