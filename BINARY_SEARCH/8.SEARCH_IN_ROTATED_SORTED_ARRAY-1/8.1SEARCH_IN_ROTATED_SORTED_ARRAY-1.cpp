#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // BRUTE FORCE APPROACH
        // TC -> O(N)
        // SC -> O(1)
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Enter target: ";
    cin >> target;
    int result = sol.search(nums, target);
    cout << "Index: " << result << endl;
    return 0;
}