#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsertHelper(vector<int> &nums, int low, int high, int target)
    {

        if (low > high)
            return low;

        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        return searchInsertHelper(nums, low, high, target);
    }
    int searchInsert(vector<int> &nums, int target)
    {
        // OPTIMAL APPROACH
        int low = 0;
        int high = nums.size() - 1;

        return searchInsertHelper(nums, low, high, target);
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