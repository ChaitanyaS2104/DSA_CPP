#include <iostream>
#include <vector>

using namespace std;

int longest_subarray(vector<int> &arr, int size, int sum);

int main()
{
    int size;
    cin >> size;
    int sum;
    cin >> sum;

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int result = longest_subarray(arr, size, sum);
    cout << "Output: " << result << endl;
    return 0;
}

int longest_subarray(vector<int> &arr, int size, int sum)
{
    int start = 0;
    int end = 1;
    int win_sum = arr[0];
    int max_len = 1;

    while (end < size)
    {
        if (win_sum + arr[end] <= sum)
        {
            win_sum += arr[end];
            end++;
        }
        else
        {
            while(win_sum + arr[end]> sum){
                win_sum -= arr[start];
                start++;
            }
            
            win_sum += arr[end];
            end++;
        }
        max_len = max(max_len, end - start);
    }
    return max_len;
}
