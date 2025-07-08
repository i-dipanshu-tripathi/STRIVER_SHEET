#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<int> &arr1, vector<int> &arr2, int k)
    {
        //  Time Complexity: O(log(min(n1, n2)))
        //  Space Complexity: O(1)

        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 > n2)
        {
            return median(arr2, arr1, k);
        }

        int low = max(0, k - n2);
        int high = min(k, n1);
        int left = k;

        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
            int l2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];

            int r1 = mid1 == n1 ? INT_MAX : arr1[mid1];
            int r2 = mid2 == n2 ? INT_MAX : arr2[mid2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }

        return -1;
    }
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        return median(a, b, k);
    }
};

int main()
{
    int n1, n2, k;
    cout << "Enter size of first array, second array, and k: ";
    cin >> n1 >> n2 >> k;
    vector<int> arr1(n1), arr2(n2);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; ++i)
        cin >> arr1[i];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; ++i)
        cin >> arr2[i];
    Solution sol;
    cout << sol.kthElement(arr1, arr2, k) << endl;
    return 0;
}