#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums);

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int res = minSubArrayLen(target, nums);
    cout << "Min length: " << res << endl;
    return 0;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int min_len = INT_MAX;

    int sum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        sum += nums[end];

        while (sum >= target) {
            min_len = min(min_len, end - start + 1);
            sum -= nums[start];
            start++;
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}

/*
2       3       1       2       4       3
s,e

2       3       1       2       4       3
s                       e
cur_sum = 6 

i = 3
cur_sum = 4
2       3       1       2       4       3
        s               e
*/