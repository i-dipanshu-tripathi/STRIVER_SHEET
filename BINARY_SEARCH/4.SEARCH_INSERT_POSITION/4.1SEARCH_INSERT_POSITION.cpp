#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // BRUTE FORCE APPROACH
        // TC -> O(N)
        // SC -> O(1)
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }

        return n;
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