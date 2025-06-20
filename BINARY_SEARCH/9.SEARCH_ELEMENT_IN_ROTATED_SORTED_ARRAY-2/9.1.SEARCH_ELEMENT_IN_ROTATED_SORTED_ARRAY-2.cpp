#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool Search(vector<int> &nums, int k)
    {
        // BRUTE FORCE APPROACH
        // TC -> O(N)
        // SC -> O(1)
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
                return true;
        }
        return false;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter element to search: ";
    cin >> k;

    Solution sol;
    if (sol.Search(nums, k))
    {
        cout << "Element found\n";
    }
    else
    {
        cout << "Element not found\n";
    }
    return 0;
}