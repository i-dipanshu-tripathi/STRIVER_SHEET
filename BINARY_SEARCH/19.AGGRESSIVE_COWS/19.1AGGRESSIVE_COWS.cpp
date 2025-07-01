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
        // BRUTE APPROACH

        /*
            Time Complexity:
            - Sorting: O(n log n)
            - For loop: O(maxDistance)
            - isPossible: O(n) per iteration
            Total: O(n log n + maxDistance * n)

            Space Complexity:
            - O(n) for storing stall positions
            */
        sort(nums.begin(), nums.end());
        int minDistance = 1;
        int maxDistance = *max_element(nums.begin(), nums.end());
        int result = 0;

        for (int i = minDistance; i <= maxDistance; i++)
        {
            bool ans = isPossible(nums, i, k);
            if (ans)
            {
                result = i;
            }
        }
        return result;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter number of cows: ";
    cin >> k;

    Solution sol;
    int ans = sol.aggressiveCows(nums, k);
    cout << "Largest minimum distance: " << ans << endl;
    return 0;
}
