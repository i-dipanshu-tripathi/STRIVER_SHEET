#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // OPTIMAL FORCE APPROACH
        // TC -> O(LOG(N))
        // SC -> O(1)

        int low = 0;
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

        return low;
    }
};

int main()
{
    cout << "Enter the size of the array " << endl;
    int size;
    cin >> size;

    cout << "Take the input for the array " << endl;
    vector<int> nums(size);

    for (int i = 0; i < size; i++)
        cin >> nums[i];

    cout << "Enter the target element" << endl;
    int target;
    cin >> target;

    Solution obj;

    cout << "Insert Position of " << target << " is at index " << obj.searchInsert(nums, target) << endl;
}