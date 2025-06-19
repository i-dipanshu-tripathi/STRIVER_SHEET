#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // C++ STL Way
        // TC -> O(LOG(N))
        // SC -> O(1)
        int n = arr.size();

        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        if (lb == n || arr[lb] != target)
            return 0;

        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

        return ub - lb;
    }
};

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    int count = sol.countFreq(arr, target);

    cout << "Count of " << target << ": " << count << endl;

    return 0;
}
