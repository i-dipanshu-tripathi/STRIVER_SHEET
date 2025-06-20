#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool Search(vector<int> &nums, int k)
    {
        // OPTIMAL APPROACH
        // TC -> O(LOG(N))
        // SC -> O(N)
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            while (low < high && nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }

            if (nums[mid] == k)
            {
                return true;
            }
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= k && k < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (nums[mid] <= nums[high])
            {
                if (nums[mid] < k && k <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Enter element to search: ";
    cin >> k;

    if (sol.Search(nums, k))
        cout << k << " found in the array." << endl;
    else
        cout << k << " not found in the array." << endl;

    return 0;
}