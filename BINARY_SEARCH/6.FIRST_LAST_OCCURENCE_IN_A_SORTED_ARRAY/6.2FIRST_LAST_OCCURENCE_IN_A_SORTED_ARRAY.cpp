#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getFirstOccurence(vector<int> &nums, int target)
    {
        int low = 0;
        int n = nums.size();
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (low == n || nums[low] != target)
            return -1;

        return low;
    }

    int getLastOccurence(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // OPTIMAL APPROACH
        // TC -> 2 O(LOG(N))
        // SC -> O(1)
        int firstOccurrence = getFirstOccurence(nums, target);
        if (firstOccurrence == -1)
        {
            return {-1, -1};
        }

        int lastOccurrence = getLastOccurence(nums, target);

        return {firstOccurrence, lastOccurrence};
    }
};

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    vector<int> result = sol.searchRange(nums, target);

    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}
