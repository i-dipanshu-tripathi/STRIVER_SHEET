#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (arr[i] > arr[i + 1])
                    return i;
            }
            else if (i == n - 1)
            {
                if (arr[i] > arr[i - 1])
                    return i;
            }
            else
            {
                if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
                {
                    return i;
                }
            }
        }
        return 0;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    Solution sol;
    int peakIndex = sol.findPeakElement(arr);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}