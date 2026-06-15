/*
In this problem we have to find the max sum that can be obtained from a sub array and return the sum
- Traverse throgh the array and keep track of the current sum till the element
- If the sum is neg we dont need that portion so set the curr_sum = 0 
- Keep track of the max sum
*/

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums);

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 3, 1, -5, 4};
    int res = maxSubArray(nums);
    cout << res << endl;
    return 0;
}

int maxSubArray(vector<int> &nums)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        max_sum = max(max_sum, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}

/*
-2  1   -3  4   -1  3   1   -5  4

i=0, max_sum = -2, curr_sum = -2 < 0
curr_sum = 0
i=1, max_sum = -2, curr_sum = 1
i=2, max_sum = 1, curr_sum = -2 < 0
curr_sum =0
i=3, max_sum = 1, curr_sum = 4
i=4, max_sum = 4, curr_sum = 3
i=5, max_sum = 4, curr_sum = 6
i=6, max_sum = 6, curr_sum = 7
i=7, max_sum = 7, curr_sum = 2
i=8, max_sum = 7, curr_sum = 6
i=9, max_sum = 7 stop
*/