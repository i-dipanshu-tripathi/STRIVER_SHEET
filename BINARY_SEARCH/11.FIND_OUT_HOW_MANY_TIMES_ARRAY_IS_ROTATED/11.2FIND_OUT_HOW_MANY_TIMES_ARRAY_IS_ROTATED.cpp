#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int minElement = INT_MAX;
        int minIndex = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= arr[high])
            {
                if (minElement > arr[mid])
                {
                    minElement = arr[mid];
                    minIndex = mid;
                }
                high = mid - 1;
            }
            else if (arr[low] <= arr[mid])
            {
                if (minElement > arr[low])
                {
                    minElement = arr[low];
                    minIndex = low;
                }
                low = mid + 1;
            }
        }

        return minIndex;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Solution sol;
    int k = sol.findKRotation(arr);
    cout << "Index of minimum element (number of rotations): " << k << endl;
    return 0;
}