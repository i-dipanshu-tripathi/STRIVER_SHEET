#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int midDistance, int k)
    {
        int cowPlaced = 1;
        int prevPos = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - prevPos >= midDistance)
            {
                cowPlaced++;
                prevPos = nums[i];
            }
        }
        return cowPlaced >= k;
    }

    int aggressiveCows(vector<int> &nums, int k)
    {
        /*
        Time Complexity: O(N log(maxDist)), where N = nums.size(), maxDist = max(nums) - min(nums)
            - Sorting: O(N log N)
            - Binary search: O(log(maxDist))
            - For each binary search step, isPossible runs in O(N)
        Space Complexity: O(1) extra (excluding input storage)
        */
        int minDistance = 1;
        int maxDistance = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        while (minDistance <= maxDistance)
        {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if (isPossible(nums, midDistance, k))
            {
                minDistance = midDistance + 1;
            }
            else
            {
                maxDistance = midDistance - 1;
            }
        }
        return maxDistance;
    }
};

int main()
{
    vector<int> nums = {1, 2, 8, 4, 9};
    int k = 3;
    Solution sol;
    cout << sol.aggressiveCows(nums, k) << endl;
    return 0;
}
