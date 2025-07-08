#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &arr, vector<int> &brr, int k)
    {
        // Time Complexity: O((n + m) log(n + m)), where n and m are the sizes of arr and brr.
        // Space Complexity: O(n + m), for storing the merged array.

        vector<int> crr;

        for (int i = 0; i < arr.size(); i++)
        {
            crr.push_back(arr[i]);
        }

        for (int j = 0; j < brr.size(); j++)
        {
            crr.push_back(brr[j]);
        }

        sort(crr.begin(), crr.end());

        return crr[k - 1];
    }
};

int main()
{
    Solution sol;
    int n, m, k;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> brr(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; ++i)
        cin >> brr[i];

    cout << "Enter k: ";
    cin >> k;

    int result = sol.kthElement(arr, brr, k);
    cout << "The " << k << "th element is: " << result << endl;
    return 0;
}
