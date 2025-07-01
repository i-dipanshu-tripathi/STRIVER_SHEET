#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {   // Time Complexity: O(n log n) due to sorting, where n is the size of arr.
        // Space Complexity: O(1) extra space (in-place sort).
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                k++;
        }

        return k;
    }
};

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    cout << "The " << k << "th missing positive integer is: " << sol.findKthPositive(arr, k) << endl;
    return 0;
}