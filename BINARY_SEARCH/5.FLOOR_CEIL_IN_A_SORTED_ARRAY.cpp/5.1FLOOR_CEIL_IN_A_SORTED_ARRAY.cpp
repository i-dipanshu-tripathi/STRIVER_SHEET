#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        // BRUTE FORCE APPROACH
        // TC -> O(N)
        // SC -> O(1)
        int floor = -1, ceil = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= x)
            {
                floor = nums[i];
            }

            if (nums[i] >= x)
            {
                ceil = nums[i];
                break;
            }
        }

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