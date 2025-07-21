#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // Time Complexity: O(n), Space Complexity: O(1)
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i == 0 && nums[i] > nums[i + 1])
            {
                return i;
            }
            else if (i == n - 1 && nums[i] > nums[i - 1])
            {
                return i;
            }
            else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution sol;
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}