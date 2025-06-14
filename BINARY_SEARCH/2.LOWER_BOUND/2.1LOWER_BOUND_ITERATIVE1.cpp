#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        // lower bound element is smallest element greater than or equal to the given no arr[i]>=x
        // SC -> O(1)
        // TC -> O(N)

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= x)
                return i;
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

    cout << "Lower bound of " << target << " is at index " << obj.lowerBound(nums, target) << endl;
}