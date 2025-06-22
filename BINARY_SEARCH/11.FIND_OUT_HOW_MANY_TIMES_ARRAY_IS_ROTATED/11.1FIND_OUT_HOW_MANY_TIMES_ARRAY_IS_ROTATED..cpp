#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return i;
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
    int k = sol.findKRotation(arr);
    cout << "Array is rotated " << k << " times." << endl;

    return 0;
}