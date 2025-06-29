#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> nums, int limit, int mid)
    {
        double sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum += ceil(((nums[i] * 1.0) / mid));
        }

        return sum <= limit;
    }

    int smallestDivisor(vector<int> &nums, int limit)
    {
        int low = 1;
        int high = INT_MAX;
        sort(nums.begin(), nums.end());

        /*
         * Time Complexity: O(N * log(M)), where N is the size of nums and M is the maximum possible value of the divisor (up to max(nums)).
         * Space Complexity: O(1), excluding the input vector.
         */

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, limit, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    int n, limit;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Enter limit: ";
    cin >> limit;

    Solution sol;
    int result = sol.smallestDivisor(nums, limit);
    cout << "Smallest Divisor: " << result << endl;
    return 0;
}
