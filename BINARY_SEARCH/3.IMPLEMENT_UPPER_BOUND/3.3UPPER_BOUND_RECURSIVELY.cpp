#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBoundHelper(vector<int> &nums, int low, int high, int x)
    {

        if (low > high)
            return low;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return upperBoundHelper(nums, low, high, x);
    }
    int upperBound(vector<int> &nums, int x)
    {
        // Upper bound element is smallest element greater than or equal to the given no arr[i]>x
        // SC -> O(LOG(N)) DUE TO RECURSIVE CALL STACK
        // TC -> O(LOG(N))
        return upperBoundHelper(nums, 0, nums.size() - 1, x);
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

    cout << "Lower bound of " << target << " is at index " << obj.upperBound(nums, target) << endl;
}