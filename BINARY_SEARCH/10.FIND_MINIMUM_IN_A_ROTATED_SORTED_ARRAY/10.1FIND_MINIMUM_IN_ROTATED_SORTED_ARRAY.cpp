#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int minElement = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            minElement = min(minElement, arr[i]);
        }

        return minElement;
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
    int result = sol.findMin(arr);
    cout << "Minimum element is: " << result << endl;
    return 0;
}