#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getFloor(vector<int> &nums, int x)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high == -1 ? high : nums[high];
    }

    int getCeil(vector<int> &nums, int x)
    {
        int low = 0;
        int high = nums.size() - 1;
        int n = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low == n ? -1 : nums[low];
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        // OPTIMAL APPROACH

        int floor = getFloor(nums, x);
        int ceil = getCeil(nums, x);

        return {floor, ceil};
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

    vector<int> floorAndCeil = obj.getFloorAndCeil(nums, target);
    cout << "Floor and Ceil of  " << target << " are " << floorAndCeil[0] << " " << floorAndCeil[1] << endl;
}