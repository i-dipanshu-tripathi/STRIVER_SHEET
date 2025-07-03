#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        // Time Complexity: O((maxSum - minSum + 1) * n), where n is the size of nums
        // Space Complexity: O(1) extra (excluding input)
        int minimumSum = *max_element(nums.begin(), nums.end());
        int maximumSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        for (int sum = minimumSum; sum <= maximumSum; sum++)
        {
            int currSum = 0;
            int currSplit = 1;
            for (int j = 0; j < n; j++)
            {
                if (currSum + nums[j] <= sum)
                {
                    currSum += nums[j];
                }
                else
                {
                    currSplit++;
                    currSum = nums[j];
                }
            }

            if (currSplit <= k)
                return sum;
        }
        return -1;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Enter k: ";
    cin >> k;
    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << "Minimum largest sum after split: " << result << endl;
    return 0;
}
