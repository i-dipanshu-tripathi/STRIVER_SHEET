#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getFirstOccurence(vector<int> &arr, int target)
    {
        // TC -> O(LOG(N))
        // SC -> O(1)

        int low = 0;
        int n = arr.size();
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (low == n || arr[low] != target)
            return -1;
        return low;
    }

    int getLastOccurence(vector<int> &arr, int target)
    {
        // TC -> O(LOG(N))
        // SC -> O(1)

        int low = 0;
        int n = arr.size();
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
    int countFreq(vector<int> &arr, int target)
    {

        // TC -> O(2*LOG(N))
        // SC -> O(1)

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        int firstOccurence = getFirstOccurence(arr, target);

        if (firstOccurence == -1)
        {
            return 0;
        }

        int lastOccurence = getLastOccurence(arr, target);

        return lastOccurence - firstOccurence + 1;
    }
};

int main()
{
    Solution sol;
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter target: ";
    cin >> target;
    int count = sol.countFreq(arr, target);
    cout << "Count of " << target << " is: " << count << endl;
    return 0;
}