#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

vector<int> two_sum(vector<int> &nums, int target);

int main(){
    int target;
    cout<<"Enter target: ";
    cin>>target;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int>res = two_sum(nums, target);
    for(auto& x: res){
        cout<<x<<" ";
    }
    return 0;
}

vector<int> two_sum(vector<int>& nums, int target) {
        unordered_map <int, int> dict;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(dict.find(complement) != dict.end()) return {dict[complement], i};
            dict[nums[i]] = i;
        }
        return {-1, -1};
    }