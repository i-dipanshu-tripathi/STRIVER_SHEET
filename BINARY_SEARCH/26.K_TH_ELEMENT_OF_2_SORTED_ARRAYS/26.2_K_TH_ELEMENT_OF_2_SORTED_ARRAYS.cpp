
class Solution
{
public:
    int kthElement(vector<int> &arr, vector<int> &brr, int k)
    {
        // Time Complexity: O(k)
        // Space Complexity: O(1)

        int idx1 = 0;
        int idx2 = 0;

        int kthVal = -1;
        int count = 0;

        for (int i = 0; i < k; i++)
        {
            if (idx1 < arr.size() && idx2 < brr.size())
            {
                if (arr[idx1] <= brr[idx2])
                {
                    kthVal = arr[idx1++];
                }
                else
                {
                    kthVal = brr[idx2++];
                }
            }
            else if (idx1 < arr.size())
            {
                kthVal = arr[idx1++];
            }
            else
            {
                kthVal = brr[idx2++];
            }
        }

        return kthVal;
    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cout << "Enter size of first array, second array and k: ";
    cin >> n >> m >> k;
    vector<int> arr(n), brr(m);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; ++i)
        cin >> brr[i];

    Solution sol;
    cout << "K-th element is: " << sol.kthElement(arr, brr, k) << endl;
    return 0;
}