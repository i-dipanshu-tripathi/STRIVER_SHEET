#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        //  timecomplexity O(log(min(n1, n2)))
        //  spacecomplexity O(1)

        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 > n2)
        {
            return median(arr2, arr1);
        }

        int low = 0;
        int high = n1;
        int left = (n1 + n2 + 1) / 2;

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
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

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
};

int main()
{
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; ++i)
    {
        cin >> arr2[i];
    }

    Solution sol;
    double med = sol.median(arr1, arr2);
    cout << "Median: " << med << endl;

    cout << "Time Complexity: O(log(min(n1, n2)))" << endl;
    cout << "Space Complexity: O(1)" << endl;

    return 0;
}