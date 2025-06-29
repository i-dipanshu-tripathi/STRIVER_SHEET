#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int limit)
    {
        /**
         * Time Complexity: O(N * M), where N is the size of `nums` and M is the maximum element in `nums`.
         * Space Complexity: O(1), excluding the input vector.
         */

        int maxNo = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 1; i <= maxNo; i++)
        {
            double sum = 0;

            for (int j = 0; j < n; j++)
            {
                sum += ceil((nums[j] * 1.0) / i);
            }

            if (sum <= limit)
                return i;
        }

        return -1;
    }
};

int main()
{
    int n, limit;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cin >> limit;
    Solution sol;
    cout << sol.smallestDivisor(nums, limit) << endl;
    return 0;
}