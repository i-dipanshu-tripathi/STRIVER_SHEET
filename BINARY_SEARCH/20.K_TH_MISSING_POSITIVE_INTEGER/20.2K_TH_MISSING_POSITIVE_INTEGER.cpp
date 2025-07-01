#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        //   Time Complexity: O(log n), where n is the size of the input array 'arr'.
        // Space Complexity: O(1), as only a constant amount of extra space is used.
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int missingElement = arr[mid] - (mid + 1);

            if (missingElement < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return k + low;
    }
};

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;
    Solution sol;
    int result = sol.findKthPositive(arr, k);
    cout << "Kth missing positive integer: " << result << endl;
    return 0;
}