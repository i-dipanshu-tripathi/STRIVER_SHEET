class Solution
{
public:
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Time Complexity: O(n1 + n2), where n1 and n2 are the sizes of arr1 and arr2.
        // Space Complexity: O(1), as only a constant amount of extra space is used.
        vector<int> arr3;

        int n1 = arr1.size();
        int n2 = arr2.size();
        int mid1 = -1;
        int mid2 = -1;
        int idx1 = 0;
        int idx2 = 0;

        int n = (n1 + n2) / 2;

        for (int i = 0; i <= n; i++)
        {
            mid2 = mid1;

            if (idx1 < n1 && idx2 < n2)
            {
                if (arr1[idx1] <= arr2[idx2])
                {
                    mid1 = arr1[idx1++];
                }
                else
                {
                    mid1 = arr2[idx2++];
                }
            }
            else if (idx1 < n1)
            {
                mid1 = arr1[idx1++];
            }
            else
            {
                mid1 = arr2[idx2++];
            }
        }

        if ((n1 + n2) % 2 == 0)
        {
            return (mid1 + mid2) / 2.0;
        }
        return mid1;
    }
};
#include <bits/stdc++.h>
using namespace std;

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

    return 0;
}
