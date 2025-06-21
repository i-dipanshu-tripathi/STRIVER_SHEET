#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // OPTIMAL APPROACH
        // TC -> O(LOG(N))
        // SC -> O(N)
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        int minElement = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid])
            {
                minElement = min(arr[low], minElement);
                low = mid + 1;
            }
            else
            {
                minElement = min(arr[mid], minElement);
                high = mid - 1;
            }
        }

        return minElement;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr;
    arr.reserve(n); // Reserve space for efficiency

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Solution sol;
    int minElement = sol.findMin(arr);
    cout << "Minimum element in rotated sorted array: " << minElement << endl;
    return 0;
}
