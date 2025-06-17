#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // BRUTE FORCE APPROACH
        // TC -> O(N)
        // SC -> O(N)
        int fo = -1;
        int lo = -1;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (fo == -1 && nums[i] == target)
            {
                fo = i;
                lo = i;
            }
            else if (nums[i] == target)
            {
                lo = i;
            }
        }

        return {fo, lo};
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
}