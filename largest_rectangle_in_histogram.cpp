/*
In this question we have to find the largest rectangle possible and return its area
- We initialis left and right pointers to the current number
- For each element
    - If the numbers on left are greater than or equal to curr move left pointer (l--)
    - If the numbers on right are greater than or equal to curr move right pointer (r++)
    - Calculate area and update the max area
*/
#include<iostream>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int> &heights);

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int res = largestRectangleArea(heights);
    cout<<"Largest rectangle: "<<res<<endl;
    return 0;
}

int largestRectangleArea(vector<int> &heights)
{
    int l, r;
    int n = heights.size();
    int max_area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        l = i;
        r = i;
        while (l >= 0 && heights[l] >= heights[i])
        {
            l--;
        }
        while (r < n && heights[r] >= heights[i])
        {
            r++;
        }
        int area = heights[i] * (r - l - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}

/*
2   1   5   6   2   3

i=0, l=0, r=0
l=-1, r=1, area=2*(1+1-1)=2

i=1, l=1, r=1


*/