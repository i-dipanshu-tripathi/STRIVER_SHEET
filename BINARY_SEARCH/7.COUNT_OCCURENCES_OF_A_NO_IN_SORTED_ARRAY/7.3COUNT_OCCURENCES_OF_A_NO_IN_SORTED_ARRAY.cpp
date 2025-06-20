#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // Brute Force Way
        // TC -> O(N)
        // SC -> O(1)
        int count = 0;
        for (int num : arr)
        {
            if (num == target)
                count++;
        }
        return count;
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
