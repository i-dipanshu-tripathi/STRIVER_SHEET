#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int currSum, int k)
    {
        int noOfSplits = 1;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] <= currSum)
            {
                sum += nums[i];
            }
            else
            {
                noOfSplits++;
                sum = nums[i];
            }
        }

        return noOfSplits <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        // Space Complexity: O(1) (excluding input storage), O(n) for input vector
        // Time Complexity: O(n * log(sum - max)), where n = nums.size(), sum = total sum of nums, max = max element in nums

        int minimumSum = *max_element(nums.begin(), nums.end());
        int maximumSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        while (minimumSum <= maximumSum)
        {
            int currSum = minimumSum + (maximumSum - minimumSum) / 2;

            if (isPossible(nums, currSum, k))
            {
                maximumSum = currSum - 1;
            }
            else
            {
                minimumSum = currSum + 1;
            }
        }

        return minimumSum;
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
    {
        cin >> nums[i];
    }
    cout << "Enter number of splits (k): ";
    cin >> k;

    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << "Minimum largest sum after splitting: " << result << endl;
    return 0;
}