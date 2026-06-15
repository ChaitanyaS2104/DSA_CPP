/*
In this question we have to find the number of sub arrays whose sum is equal to the target 
- Array can have 0 & neg numbers (Sliding window cannot be used for such cases)

Brute force 
- Find sum of all possible sub arrays and update the count based on the sum and target of each

Optimal 
- Build a prefix sum array for all the elements
- target = p[j] - p[i-1]
- Add in the map sum {0 : 1} for sub arr starting from start
- We need to find if the sum req exists before and how many times (Use hash map with sum and freq of that sum)  
    p[i-1] = p[j] - target
    Update the count += freq
    Add current sum with the freq in map {sum : freq}

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

int sum_eq_k(vector<int> &nums, int k);

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
    int res = sum_eq_k(nums, target);
    cout<<res<<endl;
    return 0;
}

int sum_eq_k(vector<int>& nums, int k) {
        int n = nums.size();
        int sub_arr = 0;

        unordered_map<int, int> sum_count;
        int p = 0;
        sum_count[0] = 1;
        
        for (int i = 0; i < n; i++) {
            p += nums[i];
            sub_arr += sum_count[p - k];
            sum_count[p]++;
        }
        return sub_arr;
    }